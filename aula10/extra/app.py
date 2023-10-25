import streamlit as st
import cv2
import numpy as np
from time import sleep

st.title("Simulador de Filtro da Mediana")
st.text("Altos valores iniciais para x, y, 'box size' podem resultar em delay.")

btn = st.button("Play")

image = cv2.imread("./lena.pgm")
grayscale_image = cv2.imread("./lena.pgm", -1)
final_image = np.zeros((grayscale_image.shape), dtype=np.uint8)

box_size = st.slider("Box Size", 3, 25, 3, 2)

col1, col2 = st.columns(2)

starting_x = col1.slider("Starting x:", 0, grayscale_image.shape[1] - 10, 150, 1)
starting_y = col2.slider("Starting y:", 0, grayscale_image.shape[0] - 10, 150, 1)

frame_delay = col1.slider("Frame Delay (ms)", 0, 1000, 0, 1)
sorting_delay = col2.slider("Flat sorting Delay (ms)", 0, 1000, 0, 1)

original_image = col1.empty()
final_image_box = col2.empty()

box_focus = col1.empty()
flat_box = col2.empty()
flag = 0

original_image.image(image, caption="Imagem Original")
final_image_box.image(final_image, caption="Final Image")

if btn:
  for y in range(box_size, grayscale_image.shape[0] - box_size):
    for x in range(box_size, grayscale_image.shape[1] - box_size):
      if (x > starting_x and y > starting_y):
        start_x, start_y = x, y
        end_x, end_y = start_x + box_size, start_y + box_size

        highlighted_image = image.copy()
        cv2.rectangle(highlighted_image, (start_x, start_y), (end_x, end_y), (0, 255, 0), 2)

        group = grayscale_image[start_y:end_y, start_x:end_x]
        flatenned = group.flatten().reshape(1, box_size * box_size)
        for i in range(box_size * box_size - 1):
          chave = flatenned[0][i+1]
          j = i+1
          while(j > 0 and chave < flatenned[0][j-1]):
            flatenned[0][j] = flatenned[0][j-1]
            j -= 1
          flatenned[0][j] = chave
          if(flag and sorting_delay > 0):
            sleep(sorting_delay/1000)
            flat_box.image(flatenned, caption="Flat", use_column_width=True)

        final_image[y, x] = flatenned[0, int((box_size*box_size)/2)]

        original_image.image(highlighted_image, caption="Imagem Original")
        box_focus.image(group, caption="Box", use_column_width=True)
        flat_box.image(flatenned, caption="Flat", use_column_width=True)
        final_image_box.image(final_image, caption="Final Image")
        if(frame_delay):
          sleep(frame_delay/1000)
        flag=1
      else:
        start_x, start_y = x, y
        end_x, end_y = start_x + box_size, start_y + box_size

        group = grayscale_image[start_y:end_y, start_x:end_x]
        flatenned = group.flatten().reshape(1, box_size * box_size)
        for i in range(box_size * box_size - 1):
          chave = flatenned[0][i+1]
          j = i+1
          while(j > 0 and chave < flatenned[0][j-1]):
            flatenned[0][j] = flatenned[0][j-1]
            j -= 1
          flatenned[0][j] = chave
        final_image[y, x] = flatenned[0, int((box_size*box_size)/2)]