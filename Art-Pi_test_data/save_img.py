'''
@ Summary: 函数img_preprocess对图片进行缩放尺寸为(32, 32)，转为int8类型,
           最后写入到文件当中，用于Art-Pi中的cifar10实验

@ file:    save_img.py
@ version: 1.0.0

@ Author: luxian@rt-thread.com
@ Date:   2021/07/06
'''

import matplotlib.pyplot as plt
import numpy as np
import cv2
import os

def img_preprocess(img_path, dataset_h, img_size):
    img = cv2.imread(img_path)
    img = cv2.resize(img, img_size)
    img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    img = img.astype(np.uint8)
    img = np.expand_dims(img, axis=0)

    label = os.path.splitext(os.path.basename(img_path))[0] # 图片的标签

    img_context = img.flatten()
    img_context = [str(i) for i in img_context]

    with open(dataset_h, "w+") as f:
        if img_size[1] == 32:
            print("#define cifar10_%s "%label + "{" + ", ".join(img_context) + "};", file=f)
        else:
            print("const static uint8_t %s[] __attribute__((aligned(128)))"%label.upper()
                  + " = {" + ", ".join(img_context) + "};", file=f)

    return img, label

def main():
    img_path = r'./test_imgs/deer.jpg'

    model_input_txt = r'./model_input.txt'
    lcd_show_txt = r'./lcd_show.txt'

    img_input_size = (32, 32)  # 为模型输入图片尺寸
    img_lcd_size = (320, 240)  # lcd 显示图片的尺寸

    img_input, _ = img_preprocess(img_path, model_input_txt, img_input_size)
    img_lcd, label = img_preprocess(img_path, lcd_show_txt, img_lcd_size)

    # 显示图片
    img_lcd = img_lcd.squeeze(axis=0)
    plt.figure("lcd image show")
    plt.imshow(img_lcd)
    plt.title(label)
    plt.show()

if __name__ == '__main__':
    main()



