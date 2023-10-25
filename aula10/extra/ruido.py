import cv2
import numpy as np


image = cv2.imread("lena.pgm")
grayscale_image = cv2.imread("lena.pgm", -1)

box_size = 3
final_image = np.zeros((grayscale_image.shape), dtype=np.uint8)

for y in range(box_size, grayscale_image.shape[0] - box_size):
  for x in range(box_size, grayscale_image.shape[1] - box_size):
    start_x, start_y = x, y
    end_x, end_y = start_x + box_size, start_y + box_size

    highlighted_image = image.copy()
    cv2.rectangle(highlighted_image, (start_x, start_y), (end_x, end_y), (0, 255, 0), 2)
    group = grayscale_image[start_y:end_y, start_x:end_x]
    flatenned = group.flatten().reshape(1, box_size * box_size)
    if(x > 300 and y > 300):
      cv2.imshow("Imagem Inicial", highlighted_image)
      cv2.imshow("Zoomed Group", group)
      cv2.imshow("Flatenned", flatenned)
      cv2.waitKey(10)
    for i in range(box_size * box_size - 1):
      chave = flatenned[0][i+1]
      j = i+1
      while(j > 0 and chave < flatenned[0][j-1]):
        flatenned[0][j] = flatenned[0][j-1]
        j -= 1
      flatenned[0][j] = chave
      if(x > 300 and y > 300):
        cv2.imshow("Flatenned", flatenned)
        cv2.waitKey(700)

    final_image[y, x] = flatenned[0, int((box_size*box_size)/2)]

    if(x > 300 and y > 300):
      cv2.imshow("Imagem Final", final_image)
      cv2.waitKey(1)

cv2.destroyAllWindows()

