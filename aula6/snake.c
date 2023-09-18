#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include "deque.h"
// #include <conio.h> /*for windows*/

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

/*Comente a função abaixo (kbhit) se usar no windows*/
int kbhit(void)
{
   struct termios oldt, newt;
   int ch;
   int oldf;
   tcgetattr(STDIN_FILENO, &oldt);
   newt = oldt;
   newt.c_lflag &= ~(ICANON | ECHO);
   tcsetattr(STDIN_FILENO, TCSANOW, &newt);
   oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
   fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
   ch = getchar();
   tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
   fcntl(STDIN_FILENO, F_SETFL, oldf);
   if (ch != EOF)
   {
      ungetc(ch, stdin);
      return 1;
   }
   return 0;
}

void initialize_field(char field[SIZE][SIZE])
{
   int i, j;
   for (i = 0; i < SIZE; i++)
   {
      for (j = 0; j < SIZE; j++)
      {
         field[i][j] = ' ';
      }
   }
}

void print_field(char field[SIZE][SIZE])
{
   int i, j;
   printf("  ");
   for (i = 0; i < SIZE; i++)
   {
      printf(" #");
   }
   printf("\n");
   for (i = 0; i < SIZE; i++)
   {
      printf(" # ");
      for (j = 0; j < SIZE; j++)
      {
         if (field[i][j] == '@')
            printf(RED "%c " RESET, field[i][j]);
         else if (field[i][j] == '*')
            printf(GRN "%c " RESET, field[i][j]);
         else
            printf("%c ", field[i][j]);
      }
      printf("#\n");
   }
   printf("  ");
   for (i = 0; i < SIZE; i++)
   {
      printf(" #");
   }
   printf("\n");
}

int finish(Deque *d)
{
   Point p1 = get_front(d);
   Point p2 = get_back(d);
   if (p1.x < 1 || p1.x > SIZE - 2 || p1.y < 1 || p1.y > SIZE - 1)
      return 1;
   else if (p2.x < 1 || p2.x > SIZE - 2 || p2.y < 1 || p2.y > SIZE - 1)
      return 1;
   else
      return 0;
}

Point newReward(int width, int height)
{
   Point reward;
   reward.x = rand() % (width - 4) + 2;
   reward.y = rand() % (height - 4) + 2;
   return reward;
}

int main()
{

   char field[SIZE][SIZE];
   initialize_field(field);
   int center = SIZE / 2;
   int snake_size = 5;
   Deque *d = create_deque();

   int i;
   for (i = center - snake_size / 2; i <= center + snake_size / 2; i++)
   {
      d = insert_front(d, (Point){center, i}, field);
   }

   Point reward = newReward(SIZE, SIZE);
   field[reward.x][reward.y] = '@';

   char pressionou_prv = ' ';
   char pressionou_act = 'w';
   int reverse = 0;
   while (!finish(d))
   {
      while ((!kbhit()) && (!finish(d)))
      {
         if (reverse)
         {
            Point p = get_front(d);
            if (pressionou_act == 'w') // cima
            {
               d = insert_front(d, (Point){p.x - 1, p.y}, field);
            }
            else if (pressionou_act == 's') // baixo
            {
               d = insert_front(d, (Point){p.x + 1, p.y}, field);
            }
            else if (pressionou_act == 'a') // esquerda
            {
               d = insert_front(d, (Point){p.x, p.y - 1}, field);
            }
            else if (pressionou_act == 'd') // direita
            {
               d = insert_front(d, (Point){p.x, p.y + 1}, field);
            }
            if ((reward.x == p.x) && (reward.y == p.y))
            {
               field[reward.x][reward.y] = '*';
               reward = newReward(SIZE, SIZE);
               field[reward.x][reward.y] = '@';
            }
            else
            {
               d = delete_back(d, field);
            }
         }
         else
         {
            Point p = get_back(d);
            if (pressionou_act == 'w') // cima
            {
               d = insert_back(d, (Point){p.x - 1, p.y}, field);
            }
            else if (pressionou_act == 's') // baixo
            {
               d = insert_back(d, (Point){p.x + 1, p.y}, field);
            }
            else if (pressionou_act == 'a') // esquerda
            {
               d = insert_back(d, (Point){p.x, p.y - 1}, field);
            }
            else if (pressionou_act == 'd') // direita
            {
               d = insert_back(d, (Point){p.x, p.y + 1}, field);
            }
            if ((reward.x == p.x) && (reward.y == p.y))
            {
               field[reward.x][reward.y] = ' ';
               reward = newReward(SIZE, SIZE);
               field[reward.x][reward.y] = '@';
            }
            else
            {
               d = delete_front(d, field);
            }
         }
         print_field(field);
         usleep(350000);
         system("clear");
         // system("cls"); /*for windows*/
      }
      if (!finish(d))
      {
         pressionou_prv = pressionou_act;
         pressionou_act = getchar();
         if ((pressionou_act == 's') && (pressionou_prv == 'w'))
         {
            reverse = !reverse;
         }
         else if ((pressionou_act == 'w') && (pressionou_prv == 's'))
         {
            reverse = !reverse;
         }
         else if ((pressionou_act == 'a') && (pressionou_prv == 'd'))
         {
            reverse = !reverse;
         }
         else if ((pressionou_act == 'd') && (pressionou_prv == 'a'))
         {
            reverse = !reverse;
         }
      }
   }
   printf("#### Perdeu :(  \n");
   return 0;
}
