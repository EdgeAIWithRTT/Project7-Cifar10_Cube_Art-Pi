## 使用 RT-AK 快速部署至 Art-Pi

1. 本项目为 `RT-AK` 的一个实战 `DEMO`。
2. 本项目可直接食用，已经集成了 `RT-Thread` 以及 `AI` 模型
3. 本项目为 RT-AK 的示例 Demo，基于 ART-PI 硬件平台和 Cifar10 数据集

## 1. RT-AK 简介

> 目前该项目为 RT-AK 的示例 Demo，基于 ART-PI 硬件平台和 Mnist 数据集。

- `RT-AK`: `RT-Thread AI Toolkit`，RT-Thread AI 套件。

`RT-AK` 是 `RT-Thread` 团队为 `RT-Thread` 实时操作系统所开发的 `AI` 套件，能够一键将 `AI` 模型部署到 RT-Thread 项目中，让用户可以 在统一的 API 之上进行业务代码开发，又能在目标平台上获极致优化的性能，从而更简单方便地开发端侧 AI 应用程序。

在 RT-AK 支持下，仅需要一行命令，即可将 AI 模型部署到 RT-Thread 系统中：

```
$ python rt_ai_tools.py --model xxx...
```

------

**我们将致力于降低嵌入式 AI 落地的难度和门槛**。

## 2. 使用 RT-thread studio 创建项目

该项目是基于 ART-PI 的模板工程，初始工程来于 RT-Thread 新建工程

经过 RT-AK 转换之后得到的一个完整的项目工程

[![img](https://gitee.com/wonderful4/images/raw/master/imgs/20210707150631.png)

## 3. 使用 RT-AK 一键部署

首先 cd 到 RT-AK 中的 rt_ai_tools 所在的目录下，输入以下命令行：

![image-20210706172843607](https://gitee.com/wonderful4/images/raw/master/imgs/20210706172843.png)

运行结果：

![image-20210706173103632](https://gitee.com/wonderful4/images/raw/master/imgs/20210706173103.png)

转换之后的目录结构：

![image-20210410154606274](https://gitee.com/wonderful4/images/raw/master/imgs/20210706173247.png)

## 4. 编译

本项目使用 RT-Thread Studio 进行编译完整项目，编译结果

![image](https://gitee.com/wonderful4/images/raw/master/imgs/20210707150944.png)

## 5. 烧录

本项目使用 RT-Thread Studio 将完整项目烧录至 Art-Pi 开发板中

![img](https://gitee.com/wonderful4/images/raw/master/imgs/20210707151025.png)

## 6. 应用开发

相关应用开发代码请参考 `RT-AK Lib` 开发手册

`RT-AK` 所提供的示例 `Demo`: [cifar10_app.c](https://github.com/EdgeAIWithRTT/Project7-Cifar10_Cube_Art-Pi/blob/v0.1.0/Art-Pi_cifar10_without_lcd/applications/cifar10_app.c)，打开一个终端，运行 `cifar10_app` 即可

![image](https://gitee.com/wonderful4/images/raw/master/imgs/20210707151142.png)
