# RT-AK 之 STM32 插件 Demo-Cifar10

[TOC]

怎么把生成 ART-PI，怎么使用 RT-AK，怎么使用 RT-Thread Sdutio 编译代码，请看下面这个链接：

[RT-AK 之 STM32 插件快速上手（附源码）](https://blog.csdn.net/weixin_37598106/article/details/118520343)

## 1. 项目说明

cifar10 分类模型，共检测10种类型图片，如飞机、卡车、船等等。

当模型训练完成之后，使用RT-AK框架，将模型一键部署到RT-Thread系统中。

训练模型已提供在 `model`  目录下。

`Demo` 示例代码实现在 `appplications` 文件夹下面，其中文件说明：

```
卷 软件 的文件夹 PATH 列表
卷序列号为 E67E-D1CA
D:.
    cifar10_app.c		// ai 模型推理应用代码实现
    main.c			// artpi LED 闪烁灯例程原 main 函数，未改动
    rt_ai_cifar10_model.c			// 与 STM32 平台相关的模型声明文件
    rt_ai_cifar10_model.h			// 存放 ai 模型输入输出等相关信息文件
    SConscript
```

结果显示：

![image-20210708154031750](C:\Users\Admin\AppData\Roaming\Typora\typora-user-images\image-20210708154031750.png)

---

其中开启模型推理一次计时的宏定义是在 `rt_ai_lib/aiconfig.h` 文件中的第23行。

![image-20210706141158050](https://gitee.com/lebhoryi/PicGoPictureBed/raw/master/img/20210706141226.png)

## 2. 元件

多媒体扩展版

## 3. 步骤

### 3.1 代码流程

**RT-AK Lib 模型加载并运行**：

- 注册模型（代码自动注册，无需修改）
- 找到注册模型
- 初始化模型，挂载模型信息，准备运行环境
- 运行（推理）模型
- 获取输出结果

### 3.2 核心代码

```c
// cifar10_app.c

...

// 注册模型的代码在 rt_ai_cifar10_model.c 文件下的第43行，代码自动执行
// 模型的相关信息在 rt_ai_cifar10_model.h 文件
// find a registered model handle
model = rt_ai_find(RT_AI_CIFAR10_MODEL_NAME);  // 找到模型
...
result = rt_ai_init(model, work_buffer);  // 初始化模型，传入输入数据
...
result = rt_ai_run(model, ai_run_complete, &ai_run_complete_flag);    // 模型推理一次
...

/* 获取模型输出结果 */
uint8_t *out = (uint8_t *)rt_ai_output(model, 0);
```

------

**如何更换模型输入数据补充说明**：

模型不用重新训练，只需要更改模型输入图片即可。

在文件夹 `cifar10_data` 中，将自己的图片放到图片保存地址中，修改 save_img.py 对应参数，即可生成图片数据到 model_input.txt 中。

![image-20210708153812513](https://gitee.com/wonderful4/images/raw/master/imgs/20210708154139.png)

最后按照 cifar10_app.c 中的格式写入

![image-20210708103208595](https://gitee.com/wonderful4/images/raw/master/imgs/20210708154221.png)

然后修改  cifar10_app.c 中的第57行中的 rt_memcpy中的第二个参数即可

![image-20210708103244337](https://gitee.com/wonderful4/images/raw/master/imgs/20210708154217.png)

### 3.3 编译说明

这里我用的是 `RT-Thread Studio`

![image-20210706142445929](https://gitee.com/lebhoryi/PicGoPictureBed/raw/master/img/20210706142450.png)

## 4. 运行结果

开机屏幕是白色的，

当在终端输入 cifar10_app 之后会有 1s 的 logo 显示，然后黑屏。之后终端输出推理结果。

![image-20210708153602571](https://gitee.com/wonderful4/images/raw/master/imgs/20210708153602.png)

![image-20210708153415670](https://gitee.com/wonderful4/images/raw/master/imgs/20210708154211.png)
