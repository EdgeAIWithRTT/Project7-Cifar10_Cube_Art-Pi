# RT-AK 之 STM32 插件 Demo-Cifar10 
| Version                                                      | Date       | Description                                                 | Other |
| ------------------------------------------------------------ | ---------- | ----------------------------------------------------------- | ----- |
| [v0.1.0](https://git.rt-thread.com/luxian/art-pi_cifar10_without_lcd/-/tree/v0.1.0) | 2021/07/07 | Cifar10分类模型部署到 ART-PI 中                             |       |
| [v0.2.0](https://git.rt-thread.com/luxian/art-pi_cifar10_without_lcd/-/tree/v0.2.0) | 2021/07/08 | 1. 新增 LCD 和 摄像头驱动; 2. 新增使用命令之后 logo 1s 显示 |       |

## 1. RT-AK 简介

- `RT-AK`: `RT-Thread AI Toolkit`，RT-Thread AI 套件。

`RT-AK` 是 `RT-Thread` 团队为 `RT-Thread` 实时操作系统所开发的 `AI` 套件，能够一键将 `AI` 模型部署到 RT-Thread 项目中，让用户可以 在统一的 API 之上进行业务代码开发，又能在目标平台上获极致优化的性能，从而更简单方便地开发端侧 AI 应用程序。

在 RT-AK 支持下，仅需要一行命令，即可将 AI 模型部署到 RT-Thread 系统中：

```
$ python rt_ai_tools.py --model xxx...
```

怎么把生成 ART-PI，怎么使用 RT-AK，怎么使用 RT-Thread Sdutio 编译代码，请看下面这个链接：

[RT-AK 之 STM32 插件快速上手（附源码）](https://blog.csdn.net/weixin_37598106/article/details/118520343)

## 2. 版本说明

版本号对应各个分支，当前 master 分支仅有上位机的训练代码、模型量化代码以及示例数据生成代码