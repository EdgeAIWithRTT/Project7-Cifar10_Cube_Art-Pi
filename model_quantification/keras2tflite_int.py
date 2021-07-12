import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'
import cv2
import time
import random
from tqdm import tqdm
import numpy as np
import tensorflow as tf
from pathlib import Path

def create_training_data():
    training_data = []
    for category in CATEGORIES:

        path = os.path.join(DATADIR, category)
        class_num = CATEGORIES.index(category)  # get the classification  (0 or a 1). 0=C 1=O

        for img in tqdm(os.listdir(path)[:100]):  # iterate over each image
            try:
                img_array = cv2.imread(os.path.join(path,img))  # convert to array
                img_array = cv2.cvtColor(img_array, cv2.COLOR_BGR2RGB)
                new_array = cv2.resize(img_array, (IMG_SIZE, IMG_SIZE))  # resize to normalize data size
                training_data.append([new_array, class_num])  # add this to our training_data
            except Exception as e:  # in the interest in keeping the output clean...
                pass

    return training_data


def representative_data_gen():
    for input_value in X:
        input_value = np.expand_dims(input_value, axis=0)
        input_value = input_value.astype(np.float32)
        yield [input_value]


def main():
    # 单个测试样本数据
    image = cv2.imread(test_path)
    image = cv2.resize(image, img_shape)
    image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    image = np.expand_dims(image, axis=0)
    image.flatten()
    print(image)
    # # 恢复 keras 模型，并预测
    # model = tf.keras.models.load_model(keras_file)
    # # tmp = model.predict(image_bn)
    # # tmp2 = np.argmax(tmp)
    # # print()
    #
    # # 动态量化 dynamic range quantization
    # converter = tf.lite.TFLiteConverter.from_keras_model(model)
    # converter.optimizations = [tf.lite.Optimize.DEFAULT]
    # converter.representative_dataset = representative_data_gen
    # # Ensure that if any ops can't be quantized, the converter throws an error
    # converter.target_spec.supported_ops = [tf.lite.OpsSet.TFLITE_BUILTINS_INT8]
    # # Set the input and output tensors to uint8 (APIs added in r2.3)
    # converter.inference_input_type = tf.uint8
    # converter.inference_output_type = tf.uint8
    #
    # tflite_model = converter.convert()
    #
    # tflite_file.write_bytes(tflite_model)

    # tflite 模型推理
    interpreter = tf.lite.Interpreter(model_path=str(tflite_file))
    interpreter.allocate_tensors()

    # Get input and output tensors.
    input_details = interpreter.get_input_details()[0]
    output_details = interpreter.get_output_details()[0]

    interpreter.set_tensor(input_details['index'], image)

    start_time = time.time()
    interpreter.invoke()
    stop_time = time.time()

    # interpreter = tf.lite.Interpreter(model_content=tflite_model)
    input_type = interpreter.get_input_details()[0]['dtype']
    print('input: ', input_type)
    output_type = interpreter.get_output_details()[0]['dtype']
    print('output: ', output_type)

    output_data = interpreter.get_tensor(output_details['index'])
    print(output_data)
    print(f"prediction: {CATEGORIES[np.argmax(output_data)]}")
    print('time: {:.3f}ms'.format((stop_time - start_time) * 1000))
    print("model size: {:.2f} MB".format(os.path.getsize(tflite_file)/1024/1024))




if __name__ == "__main__":
    DATADIR = './dataset'
    CATEGORIES = ['airplane', 'automobile', 'bird', 'cat', 'deer', 'dog', 'frog', 'horse', 'ship', 'truck']
    IMG_SIZE = 32
    test_path = "./test_imgs/deer.jpg"
    img_shape = (32, 32)
    keras_file = './cifar10_model_float32.h5'
    tflite_file = Path("./cifar10_int8.tflite")
    training_data = create_training_data()
    random.shuffle(training_data)
    X, Y = [], []
    for features, label in training_data:
        X.append(features)
        Y.append(label)

    X = np.array(X).reshape(-1, IMG_SIZE, IMG_SIZE, 3)
    X = X / 255.
    Y = np.array(Y)
    main()