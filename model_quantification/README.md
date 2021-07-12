# 模型训练和量化

### 1. 模型训练

​		`cifar10_train.ipynb` 为模型训练代码，在 jupyter notebook 上进行训练。训练集使用 tensorflow 官方 API 进行下载和处理。

​		我们使用的是 keras 框架，最后保存下来的是 `cifar10_float32.h5` 模型文件。该模型文件是 **float32** 类型的，不利于在 Art-Pi 上进行推理，所以我们接下来会进行量化。

### 2. 模型量化

​		`keras2tflite_int.py` 是模型量化代码，`quantitative_dataset` 文件夹是量化数据集。最终我们将训练保存的模型量化成 **unit8** 类型的模型文件，即 `cifar10_uint8.tflite`。

​		`test_imgs` 文件夹是对量化模型进行推理所用数据，用来检验量化后的模型的精确度。



