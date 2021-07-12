/**
  ******************************************************************************
  * @file    cifar10.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Wed Jul  7 18:20:28 2021
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "cifar10.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "layers.h"



#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#define AI_TOOLS_VERSION_MAJOR 5
#define AI_TOOLS_VERSION_MINOR 2
#define AI_TOOLS_VERSION_MICRO 0


#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 3
#define AI_TOOLS_API_VERSION_MICRO 0

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_cifar10
 
#undef AI_CIFAR10_MODEL_SIGNATURE
#define AI_CIFAR10_MODEL_SIGNATURE     "5f7eeb74812bc0bfc7013796cba020b2"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     "(rev-5.2.0)"
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Wed Jul  7 18:20:28 2021"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_CIFAR10_N_BATCHES
#define AI_CIFAR10_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array conv2d_18_scratch2_array;   /* Array #0 */
AI_STATIC ai_array conv2d_18_scratch1_array;   /* Array #1 */
AI_STATIC ai_array conv2d_18_scratch0_array;   /* Array #2 */
AI_STATIC ai_array conv2d_17_scratch1_array;   /* Array #3 */
AI_STATIC ai_array conv2d_17_scratch0_array;   /* Array #4 */
AI_STATIC ai_array conv2d_16_scratch1_array;   /* Array #5 */
AI_STATIC ai_array conv2d_16_scratch0_array;   /* Array #6 */
AI_STATIC ai_array conv2d_15_scratch1_array;   /* Array #7 */
AI_STATIC ai_array conv2d_15_scratch0_array;   /* Array #8 */
AI_STATIC ai_array conv2d_14_scratch1_array;   /* Array #9 */
AI_STATIC ai_array conv2d_14_scratch0_array;   /* Array #10 */
AI_STATIC ai_array conv2d_13_scratch1_array;   /* Array #11 */
AI_STATIC ai_array conv2d_13_scratch0_array;   /* Array #12 */
AI_STATIC ai_array conv2d_12_scratch1_array;   /* Array #13 */
AI_STATIC ai_array conv2d_12_scratch0_array;   /* Array #14 */
AI_STATIC ai_array conv2d_11_scratch1_array;   /* Array #15 */
AI_STATIC ai_array conv2d_11_scratch0_array;   /* Array #16 */
AI_STATIC ai_array conv2d_10_scratch1_array;   /* Array #17 */
AI_STATIC ai_array conv2d_10_scratch0_array;   /* Array #18 */
AI_STATIC ai_array conv2d_9_scratch1_array;   /* Array #19 */
AI_STATIC ai_array conv2d_9_scratch0_array;   /* Array #20 */
AI_STATIC ai_array conv2d_8_scratch1_array;   /* Array #21 */
AI_STATIC ai_array conv2d_8_scratch0_array;   /* Array #22 */
AI_STATIC ai_array conv2d_7_scratch1_array;   /* Array #23 */
AI_STATIC ai_array conv2d_7_scratch0_array;   /* Array #24 */
AI_STATIC ai_array conv2d_6_scratch1_array;   /* Array #25 */
AI_STATIC ai_array conv2d_6_scratch0_array;   /* Array #26 */
AI_STATIC ai_array conv2d_5_scratch1_array;   /* Array #27 */
AI_STATIC ai_array conv2d_5_scratch0_array;   /* Array #28 */
AI_STATIC ai_array conv2d_4_scratch1_array;   /* Array #29 */
AI_STATIC ai_array conv2d_4_scratch0_array;   /* Array #30 */
AI_STATIC ai_array conv2d_3_scratch1_array;   /* Array #31 */
AI_STATIC ai_array conv2d_3_scratch0_array;   /* Array #32 */
AI_STATIC ai_array conv2d_2_scratch1_array;   /* Array #33 */
AI_STATIC ai_array conv2d_2_scratch0_array;   /* Array #34 */
AI_STATIC ai_array conv2d_1_scratch1_array;   /* Array #35 */
AI_STATIC ai_array conv2d_1_scratch0_array;   /* Array #36 */
AI_STATIC ai_array dense_20_bias_array;   /* Array #37 */
AI_STATIC ai_array dense_20_weights_array;   /* Array #38 */
AI_STATIC ai_array conv2d_18_bias_array;   /* Array #39 */
AI_STATIC ai_array conv2d_18_weights_array;   /* Array #40 */
AI_STATIC ai_array conv2d_17_bias_array;   /* Array #41 */
AI_STATIC ai_array conv2d_17_weights_array;   /* Array #42 */
AI_STATIC ai_array conv2d_16_bias_array;   /* Array #43 */
AI_STATIC ai_array conv2d_16_weights_array;   /* Array #44 */
AI_STATIC ai_array conv2d_15_bias_array;   /* Array #45 */
AI_STATIC ai_array conv2d_15_weights_array;   /* Array #46 */
AI_STATIC ai_array conv2d_14_bias_array;   /* Array #47 */
AI_STATIC ai_array conv2d_14_weights_array;   /* Array #48 */
AI_STATIC ai_array conv2d_13_bias_array;   /* Array #49 */
AI_STATIC ai_array conv2d_13_weights_array;   /* Array #50 */
AI_STATIC ai_array conv2d_12_bias_array;   /* Array #51 */
AI_STATIC ai_array conv2d_12_weights_array;   /* Array #52 */
AI_STATIC ai_array conv2d_11_bias_array;   /* Array #53 */
AI_STATIC ai_array conv2d_11_weights_array;   /* Array #54 */
AI_STATIC ai_array conv2d_10_bias_array;   /* Array #55 */
AI_STATIC ai_array conv2d_10_weights_array;   /* Array #56 */
AI_STATIC ai_array conv2d_9_bias_array;   /* Array #57 */
AI_STATIC ai_array conv2d_9_weights_array;   /* Array #58 */
AI_STATIC ai_array conv2d_8_bias_array;   /* Array #59 */
AI_STATIC ai_array conv2d_8_weights_array;   /* Array #60 */
AI_STATIC ai_array conv2d_7_bias_array;   /* Array #61 */
AI_STATIC ai_array conv2d_7_weights_array;   /* Array #62 */
AI_STATIC ai_array conv2d_6_bias_array;   /* Array #63 */
AI_STATIC ai_array conv2d_6_weights_array;   /* Array #64 */
AI_STATIC ai_array conv2d_5_bias_array;   /* Array #65 */
AI_STATIC ai_array conv2d_5_weights_array;   /* Array #66 */
AI_STATIC ai_array conv2d_4_bias_array;   /* Array #67 */
AI_STATIC ai_array conv2d_4_weights_array;   /* Array #68 */
AI_STATIC ai_array conv2d_3_bias_array;   /* Array #69 */
AI_STATIC ai_array conv2d_3_weights_array;   /* Array #70 */
AI_STATIC ai_array conv2d_2_bias_array;   /* Array #71 */
AI_STATIC ai_array conv2d_2_weights_array;   /* Array #72 */
AI_STATIC ai_array conv2d_1_bias_array;   /* Array #73 */
AI_STATIC ai_array conv2d_1_weights_array;   /* Array #74 */
AI_STATIC ai_array input_1_output_array;   /* Array #75 */
AI_STATIC ai_array conversion_0_output_array;   /* Array #76 */
AI_STATIC ai_array conv2d_1_output_array;   /* Array #77 */
AI_STATIC ai_array conv2d_2_output_array;   /* Array #78 */
AI_STATIC ai_array conv2d_3_output_array;   /* Array #79 */
AI_STATIC ai_array conv2d_4_output_array;   /* Array #80 */
AI_STATIC ai_array conv2d_5_output_array;   /* Array #81 */
AI_STATIC ai_array conv2d_6_output_array;   /* Array #82 */
AI_STATIC ai_array conv2d_7_output_array;   /* Array #83 */
AI_STATIC ai_array conv2d_8_output_array;   /* Array #84 */
AI_STATIC ai_array conv2d_9_output_array;   /* Array #85 */
AI_STATIC ai_array conv2d_10_output_array;   /* Array #86 */
AI_STATIC ai_array conv2d_11_output_array;   /* Array #87 */
AI_STATIC ai_array conv2d_12_output_array;   /* Array #88 */
AI_STATIC ai_array conv2d_13_output_array;   /* Array #89 */
AI_STATIC ai_array conv2d_14_output_array;   /* Array #90 */
AI_STATIC ai_array conv2d_15_output_array;   /* Array #91 */
AI_STATIC ai_array conv2d_16_output_array;   /* Array #92 */
AI_STATIC ai_array conv2d_17_output_array;   /* Array #93 */
AI_STATIC ai_array conv2d_18_output_array;   /* Array #94 */
AI_STATIC ai_array dense_20_output_array;   /* Array #95 */
AI_STATIC ai_array dense_20_fmt_output_array;   /* Array #96 */
AI_STATIC ai_array nl_21_output_array;   /* Array #97 */
AI_STATIC ai_array nl_21_fmt_output_array;   /* Array #98 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor conv2d_18_scratch2;   /* Tensor #0 */
AI_STATIC ai_tensor conv2d_18_scratch1;   /* Tensor #1 */
AI_STATIC ai_tensor conv2d_18_scratch0;   /* Tensor #2 */
AI_STATIC ai_tensor conv2d_17_scratch1;   /* Tensor #3 */
AI_STATIC ai_tensor conv2d_17_scratch0;   /* Tensor #4 */
AI_STATIC ai_tensor conv2d_16_scratch1;   /* Tensor #5 */
AI_STATIC ai_tensor conv2d_16_scratch0;   /* Tensor #6 */
AI_STATIC ai_tensor conv2d_15_scratch1;   /* Tensor #7 */
AI_STATIC ai_tensor conv2d_15_scratch0;   /* Tensor #8 */
AI_STATIC ai_tensor conv2d_14_scratch1;   /* Tensor #9 */
AI_STATIC ai_tensor conv2d_14_scratch0;   /* Tensor #10 */
AI_STATIC ai_tensor conv2d_13_scratch1;   /* Tensor #11 */
AI_STATIC ai_tensor conv2d_13_scratch0;   /* Tensor #12 */
AI_STATIC ai_tensor conv2d_12_scratch1;   /* Tensor #13 */
AI_STATIC ai_tensor conv2d_12_scratch0;   /* Tensor #14 */
AI_STATIC ai_tensor conv2d_11_scratch1;   /* Tensor #15 */
AI_STATIC ai_tensor conv2d_11_scratch0;   /* Tensor #16 */
AI_STATIC ai_tensor conv2d_10_scratch1;   /* Tensor #17 */
AI_STATIC ai_tensor conv2d_10_scratch0;   /* Tensor #18 */
AI_STATIC ai_tensor conv2d_9_scratch1;   /* Tensor #19 */
AI_STATIC ai_tensor conv2d_9_scratch0;   /* Tensor #20 */
AI_STATIC ai_tensor conv2d_8_scratch1;   /* Tensor #21 */
AI_STATIC ai_tensor conv2d_8_scratch0;   /* Tensor #22 */
AI_STATIC ai_tensor conv2d_7_scratch1;   /* Tensor #23 */
AI_STATIC ai_tensor conv2d_7_scratch0;   /* Tensor #24 */
AI_STATIC ai_tensor conv2d_6_scratch1;   /* Tensor #25 */
AI_STATIC ai_tensor conv2d_6_scratch0;   /* Tensor #26 */
AI_STATIC ai_tensor conv2d_5_scratch1;   /* Tensor #27 */
AI_STATIC ai_tensor conv2d_5_scratch0;   /* Tensor #28 */
AI_STATIC ai_tensor conv2d_4_scratch1;   /* Tensor #29 */
AI_STATIC ai_tensor conv2d_4_scratch0;   /* Tensor #30 */
AI_STATIC ai_tensor conv2d_3_scratch1;   /* Tensor #31 */
AI_STATIC ai_tensor conv2d_3_scratch0;   /* Tensor #32 */
AI_STATIC ai_tensor conv2d_2_scratch1;   /* Tensor #33 */
AI_STATIC ai_tensor conv2d_2_scratch0;   /* Tensor #34 */
AI_STATIC ai_tensor conv2d_1_scratch1;   /* Tensor #35 */
AI_STATIC ai_tensor conv2d_1_scratch0;   /* Tensor #36 */
AI_STATIC ai_tensor dense_20_bias;   /* Tensor #37 */
AI_STATIC ai_tensor dense_20_weights;   /* Tensor #38 */
AI_STATIC ai_tensor conv2d_18_bias;   /* Tensor #39 */
AI_STATIC ai_tensor conv2d_18_weights;   /* Tensor #40 */
AI_STATIC ai_tensor conv2d_17_bias;   /* Tensor #41 */
AI_STATIC ai_tensor conv2d_17_weights;   /* Tensor #42 */
AI_STATIC ai_tensor conv2d_16_bias;   /* Tensor #43 */
AI_STATIC ai_tensor conv2d_16_weights;   /* Tensor #44 */
AI_STATIC ai_tensor conv2d_15_bias;   /* Tensor #45 */
AI_STATIC ai_tensor conv2d_15_weights;   /* Tensor #46 */
AI_STATIC ai_tensor conv2d_14_bias;   /* Tensor #47 */
AI_STATIC ai_tensor conv2d_14_weights;   /* Tensor #48 */
AI_STATIC ai_tensor conv2d_13_bias;   /* Tensor #49 */
AI_STATIC ai_tensor conv2d_13_weights;   /* Tensor #50 */
AI_STATIC ai_tensor conv2d_12_bias;   /* Tensor #51 */
AI_STATIC ai_tensor conv2d_12_weights;   /* Tensor #52 */
AI_STATIC ai_tensor conv2d_11_bias;   /* Tensor #53 */
AI_STATIC ai_tensor conv2d_11_weights;   /* Tensor #54 */
AI_STATIC ai_tensor conv2d_10_bias;   /* Tensor #55 */
AI_STATIC ai_tensor conv2d_10_weights;   /* Tensor #56 */
AI_STATIC ai_tensor conv2d_9_bias;   /* Tensor #57 */
AI_STATIC ai_tensor conv2d_9_weights;   /* Tensor #58 */
AI_STATIC ai_tensor conv2d_8_bias;   /* Tensor #59 */
AI_STATIC ai_tensor conv2d_8_weights;   /* Tensor #60 */
AI_STATIC ai_tensor conv2d_7_bias;   /* Tensor #61 */
AI_STATIC ai_tensor conv2d_7_weights;   /* Tensor #62 */
AI_STATIC ai_tensor conv2d_6_bias;   /* Tensor #63 */
AI_STATIC ai_tensor conv2d_6_weights;   /* Tensor #64 */
AI_STATIC ai_tensor conv2d_5_bias;   /* Tensor #65 */
AI_STATIC ai_tensor conv2d_5_weights;   /* Tensor #66 */
AI_STATIC ai_tensor conv2d_4_bias;   /* Tensor #67 */
AI_STATIC ai_tensor conv2d_4_weights;   /* Tensor #68 */
AI_STATIC ai_tensor conv2d_3_bias;   /* Tensor #69 */
AI_STATIC ai_tensor conv2d_3_weights;   /* Tensor #70 */
AI_STATIC ai_tensor conv2d_2_bias;   /* Tensor #71 */
AI_STATIC ai_tensor conv2d_2_weights;   /* Tensor #72 */
AI_STATIC ai_tensor conv2d_1_bias;   /* Tensor #73 */
AI_STATIC ai_tensor conv2d_1_weights;   /* Tensor #74 */
AI_STATIC ai_tensor input_1_output;   /* Tensor #75 */
AI_STATIC ai_tensor conversion_0_output;   /* Tensor #76 */
AI_STATIC ai_tensor conv2d_1_output;   /* Tensor #77 */
AI_STATIC ai_tensor conv2d_2_output;   /* Tensor #78 */
AI_STATIC ai_tensor conv2d_3_output;   /* Tensor #79 */
AI_STATIC ai_tensor conv2d_4_output;   /* Tensor #80 */
AI_STATIC ai_tensor conv2d_5_output;   /* Tensor #81 */
AI_STATIC ai_tensor conv2d_6_output;   /* Tensor #82 */
AI_STATIC ai_tensor conv2d_7_output;   /* Tensor #83 */
AI_STATIC ai_tensor conv2d_8_output;   /* Tensor #84 */
AI_STATIC ai_tensor conv2d_9_output;   /* Tensor #85 */
AI_STATIC ai_tensor conv2d_10_output;   /* Tensor #86 */
AI_STATIC ai_tensor conv2d_11_output;   /* Tensor #87 */
AI_STATIC ai_tensor conv2d_12_output;   /* Tensor #88 */
AI_STATIC ai_tensor conv2d_13_output;   /* Tensor #89 */
AI_STATIC ai_tensor conv2d_14_output;   /* Tensor #90 */
AI_STATIC ai_tensor conv2d_15_output;   /* Tensor #91 */
AI_STATIC ai_tensor conv2d_16_output;   /* Tensor #92 */
AI_STATIC ai_tensor conv2d_17_output;   /* Tensor #93 */
AI_STATIC ai_tensor conv2d_18_output;   /* Tensor #94 */
AI_STATIC ai_tensor dense_20_output;   /* Tensor #95 */
AI_STATIC ai_tensor dense_20_fmt_output;   /* Tensor #96 */
AI_STATIC ai_tensor nl_21_output;   /* Tensor #97 */
AI_STATIC ai_tensor nl_21_fmt_output;   /* Tensor #98 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conversion_0_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain conv2d_1_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain conv2d_2_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain conv2d_3_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain conv2d_4_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain conv2d_5_chain;   /* Chain #5 */
AI_STATIC_CONST ai_tensor_chain conv2d_6_chain;   /* Chain #6 */
AI_STATIC_CONST ai_tensor_chain conv2d_7_chain;   /* Chain #7 */
AI_STATIC_CONST ai_tensor_chain conv2d_8_chain;   /* Chain #8 */
AI_STATIC_CONST ai_tensor_chain conv2d_9_chain;   /* Chain #9 */
AI_STATIC_CONST ai_tensor_chain conv2d_10_chain;   /* Chain #10 */
AI_STATIC_CONST ai_tensor_chain conv2d_11_chain;   /* Chain #11 */
AI_STATIC_CONST ai_tensor_chain conv2d_12_chain;   /* Chain #12 */
AI_STATIC_CONST ai_tensor_chain conv2d_13_chain;   /* Chain #13 */
AI_STATIC_CONST ai_tensor_chain conv2d_14_chain;   /* Chain #14 */
AI_STATIC_CONST ai_tensor_chain conv2d_15_chain;   /* Chain #15 */
AI_STATIC_CONST ai_tensor_chain conv2d_16_chain;   /* Chain #16 */
AI_STATIC_CONST ai_tensor_chain conv2d_17_chain;   /* Chain #17 */
AI_STATIC_CONST ai_tensor_chain conv2d_18_chain;   /* Chain #18 */
AI_STATIC_CONST ai_tensor_chain dense_20_chain;   /* Chain #19 */
AI_STATIC_CONST ai_tensor_chain dense_20_fmt_chain;   /* Chain #20 */
AI_STATIC_CONST ai_tensor_chain nl_21_chain;   /* Chain #21 */
AI_STATIC_CONST ai_tensor_chain nl_21_fmt_chain;   /* Chain #22 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_nl conversion_0_layer; /* Layer #0 */
AI_STATIC ai_layer_conv2d conv2d_1_layer; /* Layer #1 */
AI_STATIC ai_layer_conv2d conv2d_2_layer; /* Layer #2 */
AI_STATIC ai_layer_conv2d conv2d_3_layer; /* Layer #3 */
AI_STATIC ai_layer_conv2d conv2d_4_layer; /* Layer #4 */
AI_STATIC ai_layer_conv2d conv2d_5_layer; /* Layer #5 */
AI_STATIC ai_layer_conv2d conv2d_6_layer; /* Layer #6 */
AI_STATIC ai_layer_conv2d conv2d_7_layer; /* Layer #7 */
AI_STATIC ai_layer_conv2d conv2d_8_layer; /* Layer #8 */
AI_STATIC ai_layer_conv2d conv2d_9_layer; /* Layer #9 */
AI_STATIC ai_layer_conv2d conv2d_10_layer; /* Layer #10 */
AI_STATIC ai_layer_conv2d conv2d_11_layer; /* Layer #11 */
AI_STATIC ai_layer_conv2d conv2d_12_layer; /* Layer #12 */
AI_STATIC ai_layer_conv2d conv2d_13_layer; /* Layer #13 */
AI_STATIC ai_layer_conv2d conv2d_14_layer; /* Layer #14 */
AI_STATIC ai_layer_conv2d conv2d_15_layer; /* Layer #15 */
AI_STATIC ai_layer_conv2d conv2d_16_layer; /* Layer #16 */
AI_STATIC ai_layer_conv2d conv2d_17_layer; /* Layer #17 */
AI_STATIC ai_layer_conv2d_nl_pool conv2d_18_layer; /* Layer #18 */
AI_STATIC ai_layer_dense dense_20_layer; /* Layer #19 */
AI_STATIC ai_layer_nl dense_20_fmt_layer; /* Layer #20 */
AI_STATIC ai_layer_nl nl_21_layer; /* Layer #21 */
AI_STATIC ai_layer_nl nl_21_fmt_layer; /* Layer #22 */


/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch2_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2369, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2369, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2369, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2369, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2369, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 768, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2284, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  dense_20_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 10, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  dense_20_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1280, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 576, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 576, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 576, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 576, AI_STATIC)

/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 576, AI_STATIC)

/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#74 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#75 */
AI_ARRAY_OBJ_DECLARE(
  input_1_output_array, AI_ARRAY_FORMAT_U8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 3072, AI_STATIC)

/* Array#76 */
AI_ARRAY_OBJ_DECLARE(
  conversion_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3072, AI_STATIC)

/* Array#77 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#78 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#79 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#80 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#81 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#82 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#83 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#84 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#85 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  dense_20_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10, AI_STATIC)

/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  dense_20_fmt_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10, AI_STATIC)

/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  nl_21_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10, AI_STATIC)

/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  nl_21_fmt_output_array, AI_ARRAY_FORMAT_U8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 10, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_scratch2_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_20_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(3.6549328797264025e-05f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_20_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003601709846407175f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.926017547608353e-05f, 6.765274883946404e-05f, 6.816070526838303e-05f, 5.937894820817746e-05f, 8.018424705369398e-05f, 6.726245919708163e-05f, 6.96924325893633e-05f, 8.701397018739954e-05f, 6.492299871752039e-05f, 5.784160384791903e-05f, 6.54666728223674e-05f, 5.623333345283754e-05f, 7.656535308342427e-05f, 7.614840433234349e-05f, 4.9657068302622065e-05f, 9.670995495980605e-05f, 7.271704816957936e-05f, 6.003662565490231e-05f, 9.63541169767268e-05f, 6.633729935856536e-05f, 5.662417970597744e-05f, 7.575484778499231e-05f, 7.85853699198924e-05f, 7.205699512269348e-05f, 5.343927477952093e-05f, 6.395128002623096e-05f, 7.374661799985915e-05f, 8.827187411952764e-05f, 6.455217953771353e-05f, 7.241431740112603e-05f, 0.0001116075218305923f, 6.795512308599427e-05f, 5.83954642934259e-05f, 8.117841207422316e-05f, 5.6698550906730816e-05f, 6.307405419647694e-05f, 7.066477701300755e-05f, 7.269577326951548e-05f, 9.028017666423693e-05f, 7.105341501301154e-05f, 6.374258373398334e-05f, 7.293772068805993e-05f, 6.856622349005193e-05f, 7.6411830377765e-05f, 6.92947069182992e-05f, 8.729354885872453e-05f, 4.8384201363660395e-05f, 0.00010064256639452651f, 6.415365351131186e-05f, 6.649899296462536e-05f, 6.486356141977012e-05f, 6.575106090167537e-05f, 6.222666706889868e-05f, 6.285535346250981e-05f, 6.02217078267131e-05f, 6.095213393564336e-05f, 6.462435703724623e-05f, 6.548295641550794e-05f, 5.62187960895244e-05f, 7.481600914616138e-05f, 7.498118793591857e-05f, 4.721892037196085e-05f, 7.32067201170139e-05f, 0.00010486617975402623f, 6.439472053898498e-05f, 6.955068238312379e-05f, 7.848576933611184e-05f, 6.788472092011943e-05f, 8.389985305257142e-05f, 6.373479845933616e-05f, 7.997262582648546e-05f, 5.916166992392391e-05f, 7.113334868336096e-05f, 9.071633394341916e-05f, 7.219565304694697e-05f, 6.583270442206413e-05f, 5.7779456255957484e-05f, 6.728596781613305e-05f, 7.141975947888568e-05f, 6.671535811619833e-05f, 6.365982699207962e-05f, 6.744092388544232e-05f, 7.014038419583812e-05f, 6.689503788948059e-05f, 6.461379962274805e-05f, 8.110883936751634e-05f, 8.429027366219088e-05f, 6.60110090393573e-05f, 7.716246182098985e-05f, 7.237611134769395e-05f, 7.896265015006065e-05f, 6.367301102727652e-05f, 7.96805034042336e-05f, 7.84143412602134e-05f, 6.888491043355316e-05f, 5.5453594541177154e-05f, 5.3562944231089205e-05f, 6.297329673543572e-05f, 6.417407712433487e-05f, 5.330977000994608e-05f, 7.206913869595155e-05f, 7.319535507122055e-05f, 7.128455035854131e-05f, 6.777255475753918e-05f, 6.0700094763888046e-05f, 8.078340033534914e-05f, 8.42788940644823e-05f, 7.126919081201777e-05f, 7.324224134208634e-05f, 9.147810487775132e-05f, 7.208425085991621e-05f, 7.622148405062035e-05f, 6.897797720739618e-05f, 6.202551594469696e-05f, 5.96407480770722e-05f, 8.080490806605667e-05f, 7.128559082048014e-05f, 5.95939090999309e-05f, 7.042917422950268e-05f, 5.335057358024642e-05f, 5.9894617152167484e-05f, 5.385123222367838e-05f, 6.90226152073592e-05f, 9.878633136395365e-05f, 6.45653490209952e-05f, 6.57181371934712e-05f, 8.811480074655265e-05f, 6.686033884761855e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0025185574777424335f, 0.002875241916626692f, 0.0028968299739062786f, 0.0025236052460968494f, 0.003407830372452736f, 0.002858654595911503f, 0.0029619282577186823f, 0.003698093583807349f, 0.0027592272963374853f, 0.002458268078044057f, 0.002782333642244339f, 0.0023899166844785213f, 0.0032540273386985064f, 0.0032363070640712976f, 0.0021104253828525543f, 0.0041101728565990925f, 0.003090474521741271f, 0.0025515565648674965f, 0.004095050040632486f, 0.002819335088133812f, 0.0024065275210887194f, 0.003219580976292491f, 0.0033398782834410667f, 0.003062422387301922f, 0.0022711690980941057f, 0.002717929193750024f, 0.0031342313159257174f, 0.003751554526388645f, 0.002743467455729842f, 0.003077608300372958f, 0.004743319470435381f, 0.00288809253834188f, 0.002481807256117463f, 0.0034500823821872473f, 0.0024096884299069643f, 0.002680647186934948f, 0.0030032529029995203f, 0.0030895702075213194f, 0.00383690744638443f, 0.0030197701416909695f, 0.0027090597432106733f, 0.003099852940067649f, 0.0029140645638108253f, 0.003247502725571394f, 0.002945024985820055f, 0.003709975862875581f, 0.0020563285797834396f, 0.004277308937162161f, 0.0027265301905572414f, 0.002826207084581256f, 0.0027567013166844845f, 0.002794420113787055f, 0.002644633175805211f, 0.002671352354809642f, 0.002559422515332699f, 0.0025904655922204256f, 0.002746534999459982f, 0.0027830256149172783f, 0.002389298751950264f, 0.00317968032322824f, 0.003186700399965048f, 0.0020068041048943996f, 0.003111285623162985f, 0.0044568125158548355f, 0.0027367756702005863f, 0.002955903997644782f, 0.0033356451895087957f, 0.002885100431740284f, 0.003565743798390031f, 0.002708728890866041f, 0.0033988365903496742f, 0.0025143709499388933f, 0.003023167373612523f, 0.003855444025248289f, 0.0030683150980621576f, 0.002797889756038785f, 0.0024556268472224474f, 0.0028596536722034216f, 0.0030353397596627474f, 0.0028354027308523655f, 0.002705542603507638f, 0.0028662392869591713f, 0.002980966353788972f, 0.002843039110302925f, 0.002746086334809661f, 0.003447125665843487f, 0.003582336474210024f, 0.002805467927828431f, 0.00327940471470356f, 0.0030759847722947598f, 0.0033559126313775778f, 0.002706103026866913f, 0.003386421361938119f, 0.003332609310746193f, 0.0029276085551828146f, 0.0023567776661366224f, 0.002276425017043948f, 0.002676364965736866f, 0.002727398183196783f, 0.002265665214508772f, 0.003062938340008259f, 0.003110802499577403f, 0.0030295932665467262f, 0.0028803334571421146f, 0.0025797539856284857f, 0.0034332943614572287f, 0.003581852884963155f, 0.0030289404094219208f, 0.003112795064225793f, 0.0038878193590790033f, 0.0030635807197541f, 0.0032394130248576403f, 0.0029315638821572065f, 0.002636084333062172f, 0.0025347317568957806f, 0.0034342084545642138f, 0.0030296375043690205f, 0.00253274105489254f, 0.002993239788338542f, 0.002267399337142706f, 0.002545521128922701f, 0.0022886772640049458f, 0.002933461219072342f, 0.00419841893017292f, 0.002744027180597186f, 0.0027930208016186953f, 0.0037448788061738014f, 0.0028415643610060215f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.478852057829499e-05f, 6.350304465740919e-05f, 8.502471609972417e-05f, 4.798722511623055e-05f, 5.0891332648461685e-05f, 0.00011327218817314133f, 9.016856347443536e-05f, 2.2804162654210813e-05f, 7.578233635285869e-05f, 0.00010658628889359534f, 6.154072616482154e-05f, 8.417472599830944e-06f, 5.0713617383735254e-05f, 6.280144589254633e-05f, 7.845030631870031e-05f, 6.333205237751827e-05f, 9.591260459274054e-05f, 6.447589839808643e-05f, 7.565505075035617e-05f, 6.450814544223249e-05f, 7.756947161396965e-05f, 8.909509051591158e-05f, 4.448196341400035e-05f, 9.602177306078374e-05f, 0.00011184893810423091f, 9.566744847688824e-05f, 5.335588866728358e-05f, 6.290756573434919e-05f, 4.796713255927898e-06f, 0.0001583602570462972f, 7.694977102801204e-05f, 6.630918505834416e-05f, 0.00015889380301814526f, 6.19378115516156e-05f, 6.020589717081748e-05f, 6.37412304058671e-05f, 7.72605199017562e-05f, 0.00010996127093676478f, 8.574340608902276e-05f, 6.571662379428744e-05f, 6.004165697959252e-05f, 0.00010790192754939198f, 4.9457925342721865e-05f, 8.277508459286764e-05f, 7.379874296020716e-05f, 3.6665162042481825e-05f, 6.0531361668836325e-05f, 7.81444032327272e-05f, 6.773188943043351e-05f, 5.5974680435610935e-05f, 8.53807432577014e-05f, 0.000118208525236696f, 6.358746031764895e-05f, 0.00016212224727496505f, 6.358859536703676e-05f, 6.53773604426533e-05f, 5.848579166922718e-05f, 5.591958324657753e-05f, 4.3718129745684564e-05f, 0.00011100723349954933f, 7.793406985001639e-05f, 0.00010102947999257594f, 2.137977207894437e-05f, 5.5858159612398595e-05f, 6.347438466036692e-05f, 5.900260657654144e-05f, 4.4736549170920625e-05f, 5.516007149708457e-05f, 9.06547429622151e-05f, 0.00010437497985549271f, 7.822512270649895e-05f, 0.00011431107122916728f, 9.922938625095412e-05f, 7.782015018165112e-05f, 7.561627717223018e-05f, 8.357776823686436e-05f, 8.003711263881996e-05f, 4.754049950861372e-05f, 7.68127356423065e-05f, 0.00011012111644959077f, 1.9916678866138682e-05f, 7.892579742474481e-05f, 7.161282701417804e-05f, 6.882435991428792e-05f, 6.952357944101095e-05f, 2.8038288292009383e-05f, 0.0001090615478460677f, 6.589956319658086e-05f, 0.00011771033314289525f, 8.447863365290686e-05f, 6.725656567141414e-05f, 3.666710836114362e-05f, 9.187394607579336e-05f, 4.721500226878561e-05f, 6.393397052306682e-05f, 7.269623893080279e-05f, 6.699134246446192e-05f, 0.00012611756392288953f, 6.802907591918483e-05f, 6.875229155411944e-05f, 0.0001064792595570907f, 7.72702696849592e-05f, 6.242201197892427e-05f, 8.621689630672336e-05f, 6.805801967857406e-05f, 4.316374543122947e-05f, 5.8018889831146225e-05f, 7.364370685536414e-05f, 0.0001282560988329351f, 8.327037357958034e-05f, 6.265689444262534e-05f, 9.614763257559389e-05f, 8.385468390770257e-05f, 6.546884105773643e-05f, 7.515556353610009e-05f, 6.926489731995389e-05f, 6.305282295215875e-05f, 9.453685925109312e-05f, 8.598772546974942e-05f, 8.808777056401595e-05f, 7.051935972413048e-05f, 7.047698454698548e-05f, 7.0353111368604e-05f, 6.305487477220595e-05f, 9.188988042296842e-05f, 7.29093881091103e-05f, 8.146162144839764e-05f, 5.974540181341581e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003178511979058385f, 0.0026988794561475515f, 0.0036135504487901926f, 0.0020394569728523493f, 0.002162881661206484f, 0.004814067855477333f, 0.003832163754850626f, 0.0009691768791526556f, 0.003220749320462346f, 0.004529917147010565f, 0.0026154806837439537f, 0.0003577425959520042f, 0.0021553286351263523f, 0.0026690615341067314f, 0.0033341380767524242f, 0.0026916121132671833f, 0.004076285753399134f, 0.0027402257546782494f, 0.003215339733287692f, 0.002741596195846796f, 0.003296702401712537f, 0.003786541288718581f, 0.0018904834287241101f, 0.004080925136804581f, 0.00475357985123992f, 0.004065866582095623f, 0.00226762518286705f, 0.002673571463674307f, 0.00020386031246744096f, 0.006730311084538698f, 0.003270365297794342f, 0.0028181402012705803f, 0.0067529864609241486f, 0.002632356947287917f, 0.0025587505660951138f, 0.002709002234041691f, 0.003283571917563677f, 0.004673353862017393f, 0.003644094569608569f, 0.002792956540361047f, 0.0025517703033983707f, 0.004585831891745329f, 0.0021019617561250925f, 0.0035179408732801676f, 0.0031364464666694403f, 0.0015582693740725517f, 0.0025725828018039465f, 0.003321137046441436f, 0.002878605155274272f, 0.0023789238184690475f, 0.0036286814138293266f, 0.005023862235248089f, 0.0027024669107049704f, 0.006890195421874523f, 0.0027025153394788504f, 0.00277853780426085f, 0.002485646167770028f, 0.0023765822406858206f, 0.0018580204341560602f, 0.004717807285487652f, 0.003312197979539633f, 0.004293752834200859f, 0.0009086403297260404f, 0.0023739717435091734f, 0.0026976612862199545f, 0.002507610712200403f, 0.001901303301565349f, 0.0023443030659109354f, 0.0038528265431523323f, 0.004435936454683542f, 0.003324567573145032f, 0.004858220461755991f, 0.004217248875647783f, 0.0033073562663048506f, 0.00321369175799191f, 0.003552054986357689f, 0.003401577239856124f, 0.002020471263676882f, 0.003264541272073984f, 0.004680147394537926f, 0.0008464588318020105f, 0.003354346379637718f, 0.0030435449443757534f, 0.002925035310909152f, 0.0029547519516199827f, 0.0011916272342205048f, 0.004635115619748831f, 0.0028007314540445805f, 0.005002689082175493f, 0.003590341890230775f, 0.0028584038373082876f, 0.0015583520289510489f, 0.0039046425372362137f, 0.002006637630984187f, 0.0027171936817467213f, 0.00308958999812603f, 0.0028471320401877165f, 0.005359996110200882f, 0.002891235752031207f, 0.0029219721909612417f, 0.004525368567556143f, 0.0032839863561093807f, 0.0026529354508966208f, 0.0036642178893089294f, 0.0028924657963216305f, 0.0018344591371715069f, 0.0024658027105033398f, 0.0031298575922846794f, 0.005450884345918894f, 0.0035389908589422703f, 0.0026629180647432804f, 0.004086274188011885f, 0.0035638241097331047f, 0.0027824256103485823f, 0.0031941113993525505f, 0.0029437581542879343f, 0.0026797449681907892f, 0.004017816390842199f, 0.0036544781178236008f, 0.003743730252608657f, 0.0029970728792250156f, 0.002995271934196353f, 0.0029900071676820517f, 0.0026798322796821594f, 0.003905319841578603f, 0.0030986489728093147f, 0.0034621187951415777f, 0.0025391795206815004f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(6.466685590567067e-05f, 6.791025953134522e-05f, 5.018842057324946e-05f, 4.979841105523519e-05f, 5.858372605871409e-05f, 5.680093090631999e-05f, 4.543469913187437e-05f, 5.15618703502696e-05f, 8.318633626913652e-05f, 6.1009155615465716e-05f, 5.327835606294684e-05f, 5.220842649578117e-05f, 3.9000093238428235e-05f, 4.0784329030429944e-05f, 7.829177775420249e-05f, 8.516960224369541e-05f, 6.120422040112317e-05f, 8.104678272502497e-05f, 9.632738510845229e-05f, 7.48107340768911e-05f, 6.140940240584314e-05f, 6.19772108620964e-05f, 4.291434743208811e-05f, 5.589145075646229e-05f, 5.129404235049151e-05f, 6.377461977535859e-05f, 5.265201616566628e-05f, 5.929139661020599e-05f, 4.477188485907391e-05f, 4.660035847336985e-05f, 0.00010555353946983814f, 6.395446689566597e-05f, 6.19951679254882e-05f, 7.614561764057726e-05f, 5.0999235099880025e-05f, 6.479067087639123e-05f, 7.940411887830123e-05f, 3.878869756590575e-05f, 4.536897176876664e-05f, 6.147172825876623e-05f, 5.626232814393006e-05f, 4.986241401638836e-05f, 5.364109165384434e-05f, 7.704479503445327e-05f, 7.359765004366636e-05f, 4.6475288399960846e-05f, 5.599860378424637e-05f, 8.905706636141986e-05f, 7.540181832155213e-05f, 7.312225352507085e-05f, 7.004621875239536e-05f, 4.9300924729323015e-05f, 7.363302574958652e-05f, 5.746821261709556e-05f, 6.70748995617032e-05f, 4.6102595661068335e-05f, 5.6176424550358206e-05f, 5.6516710174037144e-05f, 4.6343229769263417e-05f, 5.2678507927339524e-05f, 6.239650247152895e-05f, 5.821716331411153e-05f, 5.299571785144508e-05f, 5.259623139863834e-05f, 5.7782934163697064e-05f, 7.164963608374819e-05f, 5.3163093980401754e-05f, 5.855427298229188e-05f, 5.778779450338334e-05f, 5.0910246500279754e-05f, 6.774492794647813e-05f, 4.946274930262007e-05f, 6.193045555846766e-05f, 4.562181493383832e-05f, 7.6372227340471e-05f, 6.785787991248071e-05f, 6.806031888118014e-05f, 4.582024484989233e-05f, 4.164097481407225e-05f, 4.295423059375025e-05f, 4.5192165998741984e-05f, 7.782444299664348e-05f, 5.158996282261796e-05f, 6.901408050907776e-05f, 7.037179602775723e-05f, 5.906675141886808e-05f, 5.209565642871894e-05f, 5.066554149379954e-05f, 5.59479885851033e-05f, 4.2993742681574076e-05f, 5.0286107580177486e-05f, 4.955843178322539e-05f, 5.408192009781487e-05f, 5.6134969781851396e-05f, 9.981412586057559e-05f, 5.057848829892464e-05f, 7.113155152183026e-05f, 3.865736653096974e-05f, 4.8433263145852834e-05f, 8.421773236477748e-05f, 7.602683763252571e-05f, 8.162718586390838e-05f, 6.320927786873654e-05f, 7.333324901992455e-05f, 7.176825602073222e-05f, 4.625001747626811e-05f, 4.7578196245012805e-05f, 5.8872068620985374e-05f, 5.3818876040168107e-05f, 7.244429434649646e-05f, 5.368105121306144e-05f, 5.422340473160148e-05f, 5.053898712503724e-05f, 6.0425059928093106e-05f, 7.020935299806297e-05f, 6.170923734316602e-05f, 6.622409273404628e-05f, 4.0366790926782414e-05f, 6.303468398982659e-05f, 6.722126272507012e-05f, 6.10741408308968e-05f, 6.787837628507987e-05f, 5.3560543165076524e-05f, 8.169592183548957e-05f, 6.192117143655196e-05f, 8.900314423954114e-05f, 4.486008037929423e-05f, 5.636515561491251e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0027483412995934486f, 0.002886186121031642f, 0.002133007859811187f, 0.002116432413458824f, 0.0024898082483559847f, 0.002414039568975568f, 0.0019309746567159891f, 0.0021913794334977865f, 0.00353541923686862f, 0.0025928891263902187f, 0.0022643301635980606f, 0.002218858106061816f, 0.0016575040062889457f, 0.0017333339201286435f, 0.0033274004235863686f, 0.003619707887992263f, 0.0026011792942881584f, 0.0034444881603121758f, 0.0040939138270914555f, 0.0031794561073184013f, 0.002609899500384927f, 0.0026340314652770758f, 0.0018238597549498081f, 0.002375386655330658f, 0.002179996808990836f, 0.002710421336814761f, 0.0022377106361091137f, 0.002519884379580617f, 0.0019028050592169166f, 0.0019805151969194412f, 0.004486025311052799f, 0.002718064934015274f, 0.0026347944512963295f, 0.003236188553273678f, 0.0021674674935638905f, 0.0027536035049706697f, 0.003374675055965781f, 0.001648519653826952f, 0.0019281812710687518f, 0.002612548414617777f, 0.0023911488242447376f, 0.0021191525738686323f, 0.0022797463461756706f, 0.0032744037453085184f, 0.0031279001850634813f, 0.0019751996733248234f, 0.002379940589889884f, 0.0037849252112209797f, 0.003204577136784792f, 0.003107695607468486f, 0.0029769642278552055f, 0.00209528929553926f, 0.0031294035725295544f, 0.00244239903986454f, 0.0028506831731647253f, 0.0019593602046370506f, 0.002387498039752245f, 0.0024019600823521614f, 0.001969587290659547f, 0.002238836605101824f, 0.0026518511585891247f, 0.0024742293171584606f, 0.00225231796503067f, 0.0022353397216647863f, 0.0024557746946811676f, 0.0030451095663011074f, 0.002259431406855583f, 0.0024885565508157015f, 0.0024559812154620886f, 0.002163685392588377f, 0.002879159525036812f, 0.0021021668799221516f, 0.00263204425573349f, 0.0019389271037653089f, 0.00324581959284842f, 0.0028839597944170237f, 0.002892563585191965f, 0.0019473603460937738f, 0.0017697414150461555f, 0.0018255547620356083f, 0.0019206670112907887f, 0.003307538805529475f, 0.0021925733890384436f, 0.002933098468929529f, 0.0029908011201769114f, 0.0025103369262069464f, 0.0022140652872622013f, 0.0021532855462282896f, 0.002377789467573166f, 0.0018272340530529618f, 0.002137159463018179f, 0.0021062332671135664f, 0.0022984815295785666f, 0.002385736210271716f, 0.004242100287228823f, 0.002149585634469986f, 0.0030230910051614046f, 0.0016429381212219596f, 0.00205841357819736f, 0.003579253563657403f, 0.0032311405520886183f, 0.003469155402854085f, 0.0026863941457122564f, 0.0031166630797088146f, 0.003050150815397501f, 0.0019656256772577763f, 0.002022073371335864f, 0.002502062823623419f, 0.002287302166223526f, 0.003078882582485676f, 0.002281444612890482f, 0.0023044946137815714f, 0.0021479069255292416f, 0.002568064955994487f, 0.0029838974587619305f, 0.0026226425543427467f, 0.0028145238757133484f, 0.001715588616207242f, 0.0026789740659296513f, 0.0028569037094712257f, 0.002595650963485241f, 0.0028848310466855764f, 0.0022763230372220278f, 0.00347207672894001f, 0.0026316496077924967f, 0.0037826334591954947f, 0.0019065533997491002f, 0.0023955190554261208f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00018702750094234943f, 0.0001278468844247982f, 0.00011347117106197402f, 8.461994002573192e-05f, 0.00011075370275648311f, 0.00012113547563785687f, 0.00012468588829506189f, 0.00014886503049638122f, 0.00014349458797369152f, 0.00017399807984475046f, 0.00015906211046967655f, 0.00022459727188106626f, 0.00016632293409202248f, 9.284575207857415e-05f, 0.00012009451165795326f, 0.00014184409519657493f, 0.00015589798567816615f, 0.00010918680345639586f, 0.00015178194735199213f, 0.00013396986469160765f, 0.0001909436541609466f, 0.00011336152965668589f, 0.000283265981124714f, 9.801992564462125e-05f, 0.00014905222633387893f, 9.868553024716675e-05f, 0.0001729029609123245f, 0.00015392208297271281f, 0.00016743199375923723f, 0.00016862020129337907f, 0.00013254802615847439f, 0.0001244734594365582f, 0.00017197008128277957f, 0.0001657756365602836f, 0.0001316485577262938f, 0.00011213268589926884f, 0.00013855018187314272f, 0.00011793828889494762f, 0.00016538995259907097f, 0.0001182139603770338f, 0.00015114030975382775f, 0.00013445473450701684f, 0.00013357700663618743f, 0.00011730808182619512f, 9.16031131055206e-05f, 0.00014636170817539096f, 0.0002668771194294095f, 0.00015289412112906575f, 0.0001954977778950706f, 0.00018367762095294893f, 0.0001392501435475424f, 0.00014594565436709672f, 0.00011288325913483277f, 0.0001641778799239546f, 7.812730473233387e-05f, 0.0001515273324912414f, 0.0001643314171815291f, 0.00020838752971030772f, 0.00014533386274706572f, 0.00011728070967365056f, 8.789123239694163e-05f, 0.00011542460561031476f, 8.468890155199915e-05f, 0.00015784957213327289f, 0.00012447749031707644f, 0.00015281973173841834f, 0.00019999468349851668f, 0.00014619991998188198f, 0.00012462270387914032f, 0.00011369346611900255f, 0.00015017358236946166f, 0.00010981280502164736f, 0.00015330471796914935f, 0.00015907255874481052f, 0.00011421975068515167f, 0.0001512042508693412f, 9.944889461621642e-05f, 0.00017969515465665609f, 0.0002710682456381619f, 0.00010649534669937566f, 0.00017314666183665395f, 0.00015434488886967301f, 0.00011700506001943722f, 0.00015934465045575052f, 0.0002176489942939952f, 0.0002766347024589777f, 0.000193604122614488f, 0.00011500668188091367f, 0.00014080049004405737f, 0.00016898960166145116f, 0.00015332568727899343f, 0.0001335138367721811f, 0.00011090017505921423f, 0.0002823046816047281f, 0.0001396183215547353f, 0.00016981242515612394f, 0.00016258824325632304f, 0.0001157335500465706f, 0.00016641149704810232f, 0.0001257622498087585f, 8.51105505716987e-05f, 0.00014545257727149874f, 0.0001527059794170782f, 0.00011446513235569f, 0.00010704112355597317f, 8.199428702937439e-05f, 8.860779780661687e-05f, 0.00021414020739030093f, 0.0001074263927876018f, 0.00012473002425394952f, 0.00011203298345208168f, 0.00012331486504990608f, 0.00011475063365651295f, 0.00016892673738766462f, 0.00014870463928673416f, 0.00022796362463850528f, 8.189740765374154e-05f, 0.0001441712665837258f, 0.00017302426567766815f, 0.0002590131189208478f, 0.00018116582941729575f, 0.0002130998473148793f, 0.00012581530609168112f, 0.00030703566153533757f, 0.00016891772975213826f, 7.682844443479553e-05f, 0.00016398874868173152f, 0.0001422889472451061f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007948668673634529f, 0.005433492362499237f, 0.004822524730116129f, 0.003596347523853183f, 0.004707032348960638f, 0.005148257594555616f, 0.005299150012433529f, 0.006326763425022364f, 0.006098520010709763f, 0.007394918240606785f, 0.006760139483958483f, 0.009545383974909782f, 0.00706872483715415f, 0.003945944365113974f, 0.00510401651263237f, 0.006028374191373587f, 0.006625664420425892f, 0.004640439059585333f, 0.006450732704252005f, 0.005693719256669283f, 0.008115105330944061f, 0.00481786485761404f, 0.012038803659379482f, 0.0041658468544483185f, 0.006334719713777304f, 0.004194134846329689f, 0.007348375860601664f, 0.006541688460856676f, 0.007115859538316727f, 0.007166358642280102f, 0.005633290857076645f, 0.0052901217713952065f, 0.007308728061616421f, 0.007045464124530554f, 0.005595063325017691f, 0.004765639081597328f, 0.005888382438570261f, 0.005012377165257931f, 0.007029072847217321f, 0.0050240932032465935f, 0.006423463113605976f, 0.005714326165616512f, 0.005677022505551577f, 0.004985593259334564f, 0.003893132321536541f, 0.0062203723937273026f, 0.011342277750372887f, 0.006498000118881464f, 0.008308655582368374f, 0.007806298788636923f, 0.005918130744248629f, 0.006202690303325653f, 0.00479753827676177f, 0.00697755953297019f, 0.003320410382002592f, 0.00643991120159626f, 0.006984085310250521f, 0.008856469765305519f, 0.006176689174026251f, 0.0049844300374388695f, 0.0037353772204369307f, 0.0049055456183850765f, 0.003599278163164854f, 0.0067086066119372845f, 0.005290293134748936f, 0.006494838744401932f, 0.008499774150550365f, 0.0062134964391589165f, 0.0052964650094509125f, 0.004831972066313028f, 0.006382377352565527f, 0.004667044151574373f, 0.006515450309962034f, 0.006760583724826574f, 0.004854339174926281f, 0.006426180247217417f, 0.0042265779338777065f, 0.007637043949216604f, 0.011520400643348694f, 0.004526052158325911f, 0.007358733098953962f, 0.006559657398611307f, 0.004972714930772781f, 0.006772147491574287f, 0.009250082075595856f, 0.011756975203752518f, 0.008228175342082977f, 0.004887783899903297f, 0.005984020419418812f, 0.007182057946920395f, 0.006516341585665941f, 0.0056743379682302475f, 0.004713257309049368f, 0.011997949331998825f, 0.005933778826147318f, 0.0072170281782746315f, 0.006910000462085009f, 0.004918675869703293f, 0.007072488311678171f, 0.005344895645976067f, 0.0036171982064843178f, 0.00618173461407423f, 0.006490004248917103f, 0.004864768125116825f, 0.004549247678369284f, 0.003484757151454687f, 0.003765831468626857f, 0.009100958704948425f, 0.004565621726214886f, 0.0053010256960988045f, 0.004761401563882828f, 0.0052408818155527115f, 0.004876901861280203f, 0.007179385982453823f, 0.006319947075098753f, 0.009688453748822212f, 0.003480639774352312f, 0.006127278786152601f, 0.007353531196713448f, 0.011008056811988354f, 0.007699547801166773f, 0.00905674323439598f, 0.005347150377929211f, 0.013049015775322914f, 0.007179003208875656f, 0.00326520879752934f, 0.006969521753489971f, 0.006047280039638281f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.443355571012944e-05f, 4.9315047363052145e-05f, 5.0436668971087784e-05f, 5.879068703507073e-05f, 5.5960506870178506e-05f, 5.859078009962104e-05f, 6.33857780485414e-05f, 4.2374249460408464e-05f, 5.025260543334298e-05f, 4.515541877481155e-05f, 6.205670069903135e-05f, 5.485081783263013e-05f, 5.82629072596319e-05f, 4.755463669425808e-05f, 5.413244798546657e-05f, 6.1015209212200716e-05f, 4.601281398208812e-05f, 6.02196050749626e-05f, 5.407185017247684e-05f, 6.290352757787332e-05f, 5.350612264010124e-05f, 7.618227391503751e-05f, 4.8123525630217046e-05f, 4.804960553883575e-05f, 5.915109068155289e-05f, 7.146484858822078e-05f, 4.556775456876494e-05f, 6.935769488336518e-05f, 6.175092130433768e-05f, 8.17226609797217e-05f, 5.348166450858116e-05f, 4.90874626848381e-05f, 5.30301003891509e-05f, 5.1131955842720345e-05f, 6.578156899195164e-05f, 5.5729855375830084e-05f, 5.482717460836284e-05f, 6.66862542857416e-05f, 5.095333108329214e-05f, 6.36143668089062e-05f, 6.6514709033072e-05f, 5.395209154812619e-05f, 7.146179996198043e-05f, 5.6026292440947145e-05f, 4.91038263135124e-05f, 7.743584865238518e-05f, 4.597823499352671e-05f, 5.013689224142581e-05f, 5.071545820101164e-05f, 5.435580897028558e-05f, 5.552916627493687e-05f, 6.258538633119315e-05f, 5.509091351996176e-05f, 6.002594454912469e-05f, 5.0493083108449355e-05f, 4.8887515731621534e-05f, 5.397417044150643e-05f, 5.405383126344532e-05f, 5.298223186400719e-05f, 5.773671000497416e-05f, 4.795387212652713e-05f, 4.642876592697576e-05f, 6.178138573886827e-05f, 6.585088704014197e-05f, 5.480670733959414e-05f, 9.46541185840033e-05f, 6.931975076440722e-05f, 5.929875987931155e-05f, 6.475997361121699e-05f, 5.085167140350677e-05f, 7.314911636058241e-05f, 5.9719663113355637e-05f, 4.9404850869905204e-05f, 4.972897659172304e-05f, 6.43105959170498e-05f, 4.61012423329521e-05f, 6.235197361093014e-05f, 4.510888538789004e-05f, 5.286722807795741e-05f, 6.733372720191255e-05f, 5.260753823677078e-05f, 6.150125409476459e-05f, 5.610196240013465e-05f, 6.051543459761888e-05f, 6.704305269522592e-05f, 4.8824706027517095e-05f, 4.656364399124868e-05f, 5.9398484154371545e-05f, 6.214826134964824e-05f, 6.844902964076027e-05f, 5.311885615810752e-05f, 6.481123273260891e-05f, 5.0458456826163456e-05f, 5.1769664423773065e-05f, 5.3376657888293266e-05f, 7.159430242609233e-05f, 5.9348898503230885e-05f, 4.919366983813234e-05f, 5.851145397173241e-05f, 6.028486313880421e-05f, 6.815085362177342e-05f, 6.070495510357432e-05f, 4.603145134751685e-05f, 6.546806980622932e-05f, 6.481003219960257e-05f, 4.539238216239028e-05f, 5.5429012718377635e-05f, 4.9999125621980056e-05f, 5.409392906585708e-05f, 7.193032797658816e-05f, 5.117212640470825e-05f, 5.481535117723979e-05f, 6.623729859711602e-05f, 5.1761056965915486e-05f, 4.552504833554849e-05f, 5.440590393845923e-05f, 5.126739779370837e-05f, 7.643926073797047e-05f, 5.5546948715345934e-05f, 4.2943131120409817e-05f, 5.510919072548859e-05f, 5.40016517334152e-05f, 5.294788206811063e-05f, 6.0902191762579605e-05f, 5.2276966016506776e-05f, 6.0823935200460255e-05f, 5.311954009812325e-05f, 6.865926116006449e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0031634261831641197f, 0.0020958895329385996f, 0.0021435583475977182f, 0.0024986041244119406f, 0.002378321485593915f, 0.002490108134225011f, 0.002693895483389497f, 0.0018009055638685822f, 0.0021357357036322355f, 0.0019191051833331585f, 0.0026374096050858498f, 0.0023311597760766745f, 0.0024761734530329704f, 0.0020210719667375088f, 0.002300628926604986f, 0.0025931464042514563f, 0.001955544576048851f, 0.0025593331083655357f, 0.0022980535868555307f, 0.002673399867489934f, 0.0022740100976079702f, 0.0032377466559410095f, 0.0020452497992664576f, 0.002042108215391636f, 0.0025139213539659977f, 0.0030372559558600187f, 0.0019366295309737325f, 0.0029477018397301435f, 0.002624414162710309f, 0.003473212942481041f, 0.0022729707416146994f, 0.002086217049509287f, 0.002253779210150242f, 0.002173108048737049f, 0.0027957167476415634f, 0.0023685188498347998f, 0.0023301548790186644f, 0.0028341657016426325f, 0.0021655166056007147f, 0.002703610574826598f, 0.002826875075697899f, 0.002292963908985257f, 0.003037126502022147f, 0.0023811173159629107f, 0.002086912514641881f, 0.0032910234294831753f, 0.001954074949026108f, 0.0021308178547769785f, 0.00215540686622262f, 0.0023101218976080418f, 0.0023599895648658276f, 0.0026598789263516665f, 0.002341363811865449f, 0.0025511025451123714f, 0.002145956037566066f, 0.0020777194295078516f, 0.0022939022164791822f, 0.002297287806868553f, 0.0022517447359859943f, 0.0024538100697100163f, 0.0020380394998937845f, 0.0019732224754989147f, 0.0026257087010890245f, 0.002798662520945072f, 0.0023292850237339735f, 0.004022799897938967f, 0.002946089254692197f, 0.0025201973039656878f, 0.0027522987220436335f, 0.00216119596734643f, 0.0031088374089449644f, 0.0025380856823176146f, 0.002099706092849374f, 0.002113481517881155f, 0.0027332003228366375f, 0.001959302695468068f, 0.0026499589439481497f, 0.0019171275198459625f, 0.0022468571551144123f, 0.002861683489754796f, 0.002235820284113288f, 0.0026138031389564276f, 0.0023843334056437016f, 0.0025719059631228447f, 0.0028493297286331654f, 0.00207505002617836f, 0.001978954765945673f, 0.002524435520172119f, 0.002641300903633237f, 0.0029090838506817818f, 0.002257551299408078f, 0.0027544773183763027f, 0.0021444843150675297f, 0.002200210699811578f, 0.002268507843837142f, 0.0030427577439695597f, 0.002522328170016408f, 0.0020907309371978045f, 0.002486736746504903f, 0.0025621065869927406f, 0.002896411344408989f, 0.0025799605064094067f, 0.0019563366658985615f, 0.0027823930140584707f, 0.0027544263284653425f, 0.0019291762728244066f, 0.0023557329550385475f, 0.0021249628625810146f, 0.002298991894349456f, 0.003057038877159357f, 0.002174815395846963f, 0.0023296524304896593f, 0.002815085230395198f, 0.0021998449228703976f, 0.0019348144996911287f, 0.0023122509010136127f, 0.0021788643207401037f, 0.003248668508604169f, 0.002360745333135128f, 0.0018250830471515656f, 0.0023421405348926783f, 0.00229507009498775f, 0.0022502848878502846f, 0.002588343108072877f, 0.0022217710502445698f, 0.0025850171223282814f, 0.002257580403238535f, 0.0029180184938013554f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001990874734474346f, 0.00014401727821677923f, 0.00018860527779906988f, 0.00016853107081260532f, 0.0001768142101354897f, 0.00019453100685495883f, 0.00010865327931242064f, 0.0001415770238963887f, 8.385966066271067e-05f, 0.00017217760614585131f, 0.00011910816101590171f, 0.000244451715843752f, 0.00019654358038678765f, 0.00017447173013351858f, 0.00013230607146397233f, 0.00015787557640578598f, 0.00012607569806277752f, 0.0001385463692713529f, 0.0001648243924137205f, 0.00014598715642932802f, 0.00016900333866942674f, 0.00011264346539974213f, 0.00010155174095416442f, 0.00017789480625651777f, 0.0001316570705967024f, 0.00011736556916730478f, 0.00013529046555049717f, 8.699304453330114e-05f, 0.00022793335665483028f, 0.00011805712711066008f, 0.00011860754602821544f, 0.0001573257177369669f, 0.0001780950406100601f, 0.00013461038179229945f, 0.00013006958761252463f, 0.0001258771662833169f, 0.00010764667968032882f, 0.00018733376055024564f, 0.00015436414105352014f, 0.00020804718951694667f, 0.00012091858661733568f, 0.00017250240489374846f, 0.0001866143720690161f, 0.0001490833528805524f, 0.0001364850759273395f, 0.0001963600516319275f, 0.00016650666657369584f, 0.00013613160990644246f, 0.00012995344877708703f, 0.00017042524996213615f, 0.00011316096788505092f, 0.00016668153693899512f, 0.0001631281920708716f, 0.00018196538439951837f, 0.0001652603823458776f, 0.00016311898070853204f, 0.00010901093628490344f, 0.000171501626027748f, 0.0001889811101136729f, 0.00016812204557936639f, 0.00017360452329739928f, 0.0001140291424235329f, 0.00011465453280834481f, 0.00021733962057624012f, 0.0001272815716220066f, 0.00014680949971079826f, 0.00013380174641497433f, 0.00013558226055465639f, 7.568214641651139e-05f, 9.577580203767866e-05f, 0.0001064543830580078f, 0.0003015583788510412f, 0.00017045068670995533f, 0.00014056636427994817f, 0.00013836764264851809f, 0.00018255850591231138f, 0.00018307441496290267f, 0.00015800714027136564f, 0.00013324138126336038f, 0.00016374724509660155f, 0.00016335220425389707f, 0.00018332322360947728f, 0.0001897330512292683f, 0.00013715542445424944f, 8.108827751129866e-05f, 0.0001485531684011221f, 0.0001019900810206309f, 0.00016194157069548965f, 0.0002469731552992016f, 0.00019621550745796412f, 0.00017515249783173203f, 0.0001475310418754816f, 0.00021910533541813493f, 0.00014100162661634386f, 9.633461013436317e-05f, 0.00014605282922275364f, 0.00014039583038538694f, 0.00020974138169549406f, 0.0001951650920091197f, 0.00016608355508651584f, 8.943962893681601e-05f, 0.000184470642125234f, 0.00016620024689473212f, 0.00017054098134394735f, 0.00017496326472610235f, 0.00010797032882692292f, 0.0001634746149647981f, 0.00018297485075891018f, 0.00011277331941528246f, 0.00019377862918190658f, 0.00029437875491566956f, 9.469186625210568e-05f, 8.966305176727474e-05f, 0.00017522335110697895f, 0.00021769420709460974f, 0.0001325883495155722f, 0.00026370881823822856f, 0.00013323346502147615f, 0.000162929980433546f, 0.00016723443695809692f, 0.00011410388833610341f, 0.00018885756435338408f, 0.00013798879808746278f, 0.0001570776803418994f, 0.00021301559172570705f, 0.00015453874948434532f, 0.0001608259481145069f, 0.0001271719520445913f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008461217395961285f, 0.006120733916759491f, 0.008015723899006844f, 0.007162570487707853f, 0.007514603901654482f, 0.008267567493021488f, 0.00461776414886117f, 0.006017023231834173f, 0.0035640355199575424f, 0.007317548152059317f, 0.005062096752226353f, 0.010389197617769241f, 0.008353102020919323f, 0.007415048312395811f, 0.005623007658869028f, 0.006709712091833353f, 0.005358217284083366f, 0.005888220388442278f, 0.0070050363428890705f, 0.006204454228281975f, 0.007182641886174679f, 0.00478734727948904f, 0.00431594904512167f, 0.00756052928045392f, 0.005595425609499216f, 0.004988036584109068f, 0.005749844945967197f, 0.0036972041707485914f, 0.009687167592346668f, 0.0050174277275800705f, 0.005040820688009262f, 0.006686342880129814f, 0.007569039240479469f, 0.005720941349864006f, 0.00552795734256506f, 0.00534977950155735f, 0.004574983846396208f, 0.007961684837937355f, 0.006560475565493107f, 0.008842005394399166f, 0.00513903982937336f, 0.007331352215260267f, 0.007931110449135303f, 0.006336042191833258f, 0.005800615530461073f, 0.008345302194356918f, 0.007076533045619726f, 0.005785593297332525f, 0.005523021332919598f, 0.007243073079735041f, 0.004809340927749872f, 0.007083965465426445f, 0.006932948250323534f, 0.007733528967946768f, 0.00702356593683362f, 0.006932556629180908f, 0.004632964730262756f, 0.007288818713277578f, 0.008031697012484074f, 0.007145186886191368f, 0.007378192152827978f, 0.0048462385311722755f, 0.004872817546129227f, 0.009236933663487434f, 0.005409466568380594f, 0.0062394035048782825f, 0.005686574149876833f, 0.00576224597170949f, 0.003216491313651204f, 0.004070471506565809f, 0.004524311050772667f, 0.0128162307664752f, 0.007244154345244169f, 0.005974070634692907f, 0.005880624987185001f, 0.00775873614475131f, 0.0077806622721254826f, 0.006715303286910057f, 0.005662758368998766f, 0.006959257647395134f, 0.006942468695342541f, 0.007791236974298954f, 0.00806365441530943f, 0.005829105619341135f, 0.003446251852437854f, 0.0063135093078017235f, 0.004334578290581703f, 0.0068825166672468185f, 0.010496358387172222f, 0.008339159190654755f, 0.0074439807794988155f, 0.006270069163292646f, 0.009311976842582226f, 0.005992569029331207f, 0.004094220697879791f, 0.006207245402038097f, 0.005966822616755962f, 0.008914008736610413f, 0.008294516243040562f, 0.0070585510693490505f, 0.0038011842407286167f, 0.007840001955628395f, 0.007063510362058878f, 0.007247991394251585f, 0.007435938809067011f, 0.004588739015161991f, 0.006947671063244343f, 0.007776430808007717f, 0.004792865831404924f, 0.00823559146374464f, 0.012511096894741058f, 0.004024404101073742f, 0.003810679540038109f, 0.007446992211043835f, 0.009252003394067287f, 0.005635004956275225f, 0.011207624338567257f, 0.00566242216154933f, 0.00692452397197485f, 0.007107463665306568f, 0.004849415272474289f, 0.008026446215808392f, 0.005864523816853762f, 0.0066758012399077415f, 0.009053162299096584f, 0.00656789680942893f, 0.006835102569311857f, 0.00540480762720108f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.562060687225312e-05f, 6.574244616786018e-05f, 7.034132431726903e-05f, 6.460204895120114e-05f, 7.817216101102531e-05f, 7.462279609171674e-05f, 8.806766709312797e-05f, 6.37034754618071e-05f, 8.210170199163258e-05f, 7.67839519539848e-05f, 9.85839287750423e-05f, 8.586416515754536e-05f, 6.085353379603475e-05f, 7.090163853717968e-05f, 8.266208169516176e-05f, 6.811629282310605e-05f, 5.77431965211872e-05f, 7.455728336935863e-05f, 7.014098082436249e-05f, 6.78360229358077e-05f, 7.794283737894148e-05f, 9.554756252327934e-05f, 9.93975845631212e-05f, 7.013099821051583e-05f, 6.925789784872904e-05f, 7.240144623210654e-05f, 7.804631604813039e-05f, 7.957303751027212e-05f, 7.021761120995507e-05f, 6.979354657232761e-05f, 7.020749762887135e-05f, 7.591515895910561e-05f, 6.71088564558886e-05f, 8.481596887577325e-05f, 8.365605754079297e-05f, 7.68637255532667e-05f, 0.00010657931125024334f, 8.558026456739753e-05f, 8.332786819664761e-05f, 8.015059574972838e-05f, 6.120466423453763e-05f, 7.174236816354096e-05f, 7.126418495317921e-05f, 0.00010014863801188767f, 7.064359670039266e-05f, 6.90597589709796e-05f, 7.900744094513357e-05f, 9.408365440322086e-05f, 6.171872519189492e-05f, 7.909545092843473e-05f, 8.898415399016812e-05f, 6.607611430808902e-05f, 6.741694232914597e-05f, 7.816655124770477e-05f, 7.07998697180301e-05f, 8.318563777720556e-05f, 8.942020212998614e-05f, 9.378251706948504e-05f, 9.179529297398403e-05f, 8.254673593910411e-05f, 8.708991663297638e-05f, 8.100304694380611e-05f, 7.709289639024064e-05f, 6.36445329291746e-05f, 7.419462781399488e-05f, 6.565823423443362e-05f, 8.82293243193999e-05f, 6.840252899564803e-05f, 6.823214062023908e-05f, 7.641886622877792e-05f, 7.654980436200276e-05f, 7.686140452278778e-05f, 7.666898454772308e-05f, 9.299155499320477e-05f, 6.273944745771587e-05f, 6.343617860693485e-05f, 6.05619243287947e-05f, 9.545174543745816e-05f, 7.02558463672176e-05f, 7.877007010392845e-05f, 8.718910248717293e-05f, 7.139052468119189e-05f, 8.365466783288866e-05f, 8.113076182780787e-05f, 7.432076381519437e-05f, 8.819229697110131e-05f, 7.435918087139726e-05f, 9.153242717729881e-05f, 7.21874093869701e-05f, 0.0001375972933601588f, 6.984025094425306e-05f, 6.942485924810171e-05f, 6.709826993755996e-05f, 8.60826185089536e-05f, 7.733626989647746e-05f, 7.888016261858866e-05f, 7.412858394673094e-05f, 5.9101490478497e-05f, 7.27578517398797e-05f, 6.110972753958777e-05f, 6.022439629305154e-05f, 7.767047645756975e-05f, 9.294002666138113e-05f, 6.989416579017416e-05f, 9.08632209757343e-05f, 7.169832679210231e-05f, 5.751187200075947e-05f, 6.7835149820894e-05f, 6.815145025029778e-05f, 6.959057645872235e-05f, 7.173718040576205e-05f, 9.880298603093252e-05f, 7.786050264257938e-05f, 7.293951057363302e-05f, 6.87505817040801e-05f, 8.188855281332508e-05f, 7.766502676531672e-05f, 8.913328201742843e-05f, 8.696569420862943e-05f, 6.823258445365354e-05f, 7.7509626862593e-05f, 8.204526966437697e-05f, 0.0001060237264027819f, 7.870644913055003e-05f, 8.430632442468777e-05f, 7.023376383585855e-05f, 6.943894550204277e-05f, 6.814243533881381e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0023638757411390543f, 0.0027940538711845875f, 0.002989506348967552f, 0.002745587145909667f, 0.00332231679931283f, 0.0031714686192572117f, 0.003742875764146447f, 0.0027073975652456284f, 0.0034893222618848085f, 0.0032633179798722267f, 0.004189816769212484f, 0.0036492268554866314f, 0.0025862751062959433f, 0.003013319568708539f, 0.003513138275593519f, 0.0028949424158781767f, 0.0024540857411921024f, 0.0031686844304203987f, 0.00298099173232913f, 0.0028830308001488447f, 0.003312570508569479f, 0.004060771316289902f, 0.004224397242069244f, 0.002980567514896393f, 0.0029434605967253447f, 0.0030770613811910152f, 0.003316968446597457f, 0.0033818541560322046f, 0.0029842485673725605f, 0.0029662256129086018f, 0.002983818529173732f, 0.003226394299417734f, 0.0028521264903247356f, 0.0036046786699444056f, 0.0035553823690861464f, 0.0032667082268744707f, 0.00452962052077055f, 0.0036371611058712006f, 0.0035414344165474176f, 0.003406400326639414f, 0.0026011981535702944f, 0.003049050457775593f, 0.003028727835044265f, 0.004256316926330328f, 0.0030023527797311544f, 0.002935039810836315f, 0.003357816021889448f, 0.003998555243015289f, 0.0026230458170175552f, 0.0033615566790103912f, 0.0037818264681845903f, 0.0028082348871976137f, 0.0028652199544012547f, 0.0033220783807337284f, 0.0030089945066720247f, 0.003535389667376876f, 0.0038003583904355764f, 0.003985757008194923f, 0.0039013000205159187f, 0.0035082362592220306f, 0.003701321315020323f, 0.003442629473283887f, 0.0032764479983597994f, 0.0027048925403505564f, 0.0031532715074718f, 0.00279047479853034f, 0.0037497461307793856f, 0.002907107351347804f, 0.0028998658526688814f, 0.0032478016801178455f, 0.0032533665653318167f, 0.0032666095066815615f, 0.0032584317959845066f, 0.003952140919864178f, 0.0026664265897125006f, 0.0026960375253111124f, 0.0025738817639648914f, 0.0040566991083323956f, 0.002985873259603977f, 0.0033477279357612133f, 0.003705536713823676f, 0.0030340971425175667f, 0.0035553232301026583f, 0.003448057221248746f, 0.00315863243304193f, 0.0037481726612895727f, 0.003160265041515231f, 0.003890128107741475f, 0.0030679646879434586f, 0.0058478848077356815f, 0.002968210494145751f, 0.00295055634342134f, 0.0028516764286905527f, 0.003658511210232973f, 0.0032867914997041225f, 0.0033524069003760815f, 0.0031504647340625525f, 0.0025118133053183556f, 0.003092208644375205f, 0.0025971634313464165f, 0.002559536835178733f, 0.003300995333120227f, 0.003949950914829969f, 0.0029705020133405924f, 0.0038616866804659367f, 0.003047178965061903f, 0.002444254467263818f, 0.0028829937800765038f, 0.0028964364901185036f, 0.0029575994703918695f, 0.0030488301999866962f, 0.004199126735329628f, 0.003309071296826005f, 0.0030999290756881237f, 0.0029218995478004217f, 0.0034802635200321674f, 0.0033007636666297913f, 0.0037881643511354923f, 0.0036960418801754713f, 0.0028998847119510174f, 0.0032941591925919056f, 0.00348692387342453f, 0.004506008233875036f, 0.003345024073496461f, 0.0035830186679959297f, 0.002984934952110052f, 0.0029511551838368177f, 0.002896053483709693f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00012700786464847624f, 0.0003263909020461142f, 0.00020931722247041762f, 0.00018211569113191217f, 0.00014915133942849934f, 0.00013591298193205148f, 0.00017653009854257107f, 0.00020559980475809425f, 0.00014074126374907792f, 0.00012293580221012235f, 0.00011592236842261627f, 0.0001621583360247314f, 9.483473695581779e-05f, 0.00017237324209418148f, 0.00013365900667849928f, 8.687336958246306e-05f, 0.00016324406897183508f, 0.00014821082004345953f, 0.00016605595010332763f, 0.00011158436973346397f, 0.00011150135105708614f, 0.00016095448518171906f, 0.00011464532144600525f, 0.00017519768152851611f, 0.00017771324201021343f, 0.00021759007358923554f, 0.00017387766274623573f, 0.0001468802074668929f, 0.0001824469363782555f, 0.00010723262676037848f, 0.00010752835078164935f, 0.000161186428158544f, 0.0001454648154322058f, 0.00018286163685843349f, 0.00015686938422732055f, 0.0001055442335200496f, 0.0001436183083569631f, 0.0001344989286735654f, 0.00017122186545748264f, 0.00023385146050713956f, 0.0001072862942237407f, 0.00010013954306486994f, 0.0001380254834657535f, 0.00014548987383022904f, 0.000177057008841075f, 0.00021478728740476072f, 0.00014109889161773026f, 0.0001667287724558264f, 0.00017922930419445038f, 0.00014191064110491425f, 0.00020981203124392778f, 0.0001872120628831908f, 0.0001712039957055822f, 0.00010854321590159088f, 0.00018790594185702503f, 0.00011905469000339508f, 0.00014212692622095346f, 0.00015508121578022838f, 0.00011855292541440576f, 0.00012947007780894637f, 0.00016227761807385832f, 0.000172117943293415f, 0.00010776268027257174f, 0.00010927157563855872f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00539783388376236f, 0.013871612958610058f, 0.008895982056856155f, 0.007739916909486055f, 0.0063389320857822895f, 0.005776301492005587f, 0.007502529304474592f, 0.008737991563975811f, 0.0059815035201609135f, 0.005224771331995726f, 0.004926700610667467f, 0.006891729310154915f, 0.004030476324260235f, 0.007325862534344196f, 0.005680507980287075f, 0.0036921182181686163f, 0.006937873084098101f, 0.006298959720879793f, 0.007057377602905035f, 0.0047423355281353f, 0.004738807212561369f, 0.006840565707534552f, 0.004872425924986601f, 0.007445901166647673f, 0.007552812807261944f, 0.009247577749192715f, 0.007389800623059273f, 0.006242408882826567f, 0.007753994781523943f, 0.004557386506348848f, 0.004569954704493284f, 0.006850422825664282f, 0.006182254757732153f, 0.007771619595587254f, 0.006666948553174734f, 0.004485629964619875f, 0.0061037782579660416f, 0.005716204177588224f, 0.00727692898362875f, 0.009938687086105347f, 0.004559667315334082f, 0.0042559304274618626f, 0.005866082850843668f, 0.006183319725096226f, 0.007524922490119934f, 0.009128459729254246f, 0.005996702704578638f, 0.007085972465574741f, 0.007617245428264141f, 0.0060312021523714066f, 0.008917011320590973f, 0.00795651227235794f, 0.007276169955730438f, 0.004613086581230164f, 0.00798600260168314f, 0.005059824325144291f, 0.006040394306182861f, 0.006590951234102249f, 0.005038499366492033f, 0.005502478219568729f, 0.006896798498928547f, 0.007315012626349926f, 0.004579913802444935f, 0.004644041880965233f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.127626304281875e-05f, 6.157599273137748e-05f, 7.341833406826481e-05f, 7.343821198446676e-05f, 9.43803388508968e-05f, 5.964882439002395e-05f, 5.8647394325817004e-05f, 6.489153747679666e-05f, 6.530238169943914e-05f, 7.541802915511653e-05f, 6.731759640388191e-05f, 4.870703196502291e-05f, 7.499536877730861e-05f, 5.9609472373267636e-05f, 0.00010215508518740535f, 7.929029379738495e-05f, 8.073831122601405e-05f, 8.282472845166922e-05f, 9.316589421359822e-05f, 6.909890362294391e-05f, 5.796507321065292e-05f, 6.6834814788308e-05f, 7.0776222855784e-05f, 6.536665750900283e-05f, 7.278935663634911e-05f, 7.868817920098081e-05f, 7.049954001558945e-05f, 5.904842691961676e-05f, 6.808031321270391e-05f, 5.925964069319889e-05f, 6.321726687019691e-05f, 7.355619891313836e-05f, 6.164865772007033e-05f, 5.7871158787747845e-05f, 7.562176324427128e-05f, 7.541989907622337e-05f, 6.363556167343631e-05f, 5.597671042778529e-05f, 6.223280797712505e-05f, 7.80462141847238e-05f, 7.807737711118534e-05f, 7.427678065141663e-05f, 6.247917917789891e-05f, 6.820474663982168e-05f, 6.936849968042225e-05f, 8.006626012502238e-05f, 6.643297820119187e-05f, 6.656695040874183e-05f, 6.803719588788226e-05f, 7.607113366248086e-05f, 7.2145601734519e-05f, 6.38193596387282e-05f, 8.956091187428683e-05f, 7.347748760366812e-05f, 7.469444972230121e-05f, 8.73914104886353e-05f, 9.250764560420066e-05f, 6.986878725001588e-05f, 6.294659397099167e-05f, 7.11436805431731e-05f, 8.133247320074588e-05f, 6.903242319822311e-05f, 9.063463949132711e-05f, 7.563568215118721e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #38 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003029240993782878f, 0.0026169796474277973f, 0.003120279172435403f, 0.003121123882010579f, 0.004011164419353008f, 0.0025350749492645264f, 0.00249251420609653f, 0.002757890149950981f, 0.0027753510512411594f, 0.0032052660826593637f, 0.0028609978035092354f, 0.002070048823952675f, 0.0031873031985014677f, 0.0025334025267511606f, 0.004341591149568558f, 0.003369837300851941f, 0.0034313781652599573f, 0.003520050784572959f, 0.0039595505222678185f, 0.002936703385785222f, 0.002463515615090728f, 0.002840479603037238f, 0.003007989376783371f, 0.0027780828531831503f, 0.0030935476534068584f, 0.0033442475832998753f, 0.002996230497956276f, 0.002509558107703924f, 0.002893413184210658f, 0.0025185346603393555f, 0.0026867338456213474f, 0.0031261383555829525f, 0.0026200679130852222f, 0.0024595241993665695f, 0.0032139248214662075f, 0.0032053457107394934f, 0.002704511396586895f, 0.002379010198637843f, 0.0026448944117873907f, 0.0033169640228152275f, 0.0033182883635163307f, 0.003156763268634677f, 0.002655365038663149f, 0.002898701699450612f, 0.0029481612145900726f, 0.003402816131711006f, 0.002823401475325227f, 0.002829095348715782f, 0.002891580807045102f, 0.0032330232206732035f, 0.003066187957301736f, 0.0027123228646814823f, 0.003806338645517826f, 0.0031227932777255774f, 0.0031745140440762043f, 0.00371413491666317f, 0.003931574989110231f, 0.0029694235417991877f, 0.002675230149179697f, 0.0030236064922064543f, 0.0034566300455480814f, 0.0029338779859244823f, 0.0038519720546901226f, 0.003214516444131732f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #39 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00017597732949070632f, 0.00018412081408314407f, 0.0002129968343069777f, 0.0001829480897868052f, 0.00020958784443791956f, 0.00015455135144293308f, 0.00010082012158818543f, 0.00020368020341265947f, 0.00015424760931637138f, 0.0001085516851162538f, 0.0002404965489404276f, 0.0001539950171718374f, 0.00016721588326618075f, 0.00017199314606841654f, 0.00017997293616645038f, 0.0001301579031860456f, 0.00010447871318319812f, 0.00024059855786617845f, 0.00016143415996339172f, 0.00019270805933047086f, 0.00019624270498752594f, 0.00014755433949176222f, 0.00017175865650642663f, 0.00020444902474991977f, 0.00017748819664120674f, 0.00013227001181803644f, 0.0001547528663650155f, 0.00014632137026637793f, 0.00013957767805550247f, 0.00017103657592087984f, 0.00016359976143576205f, 0.0001632595667615533f, 0.00022323116718325764f, 0.00019488405087031424f, 0.0002339354541618377f, 0.00021853089856449515f, 0.0001667935139266774f, 0.00021873548394069076f, 0.00014412451128009707f, 0.00013803053298033774f, 0.00016512785805389285f, 0.00010863333591260016f, 0.00023081066319718957f, 0.00019076319586019963f, 0.0001677120744716376f, 0.00014452914183493704f, 0.00013838274753652513f, 0.00013976996706333011f, 0.0001707153714960441f, 0.00017580401618033648f, 0.00016711435455363244f, 0.00012555229477584362f, 0.000137522496515885f, 0.00013268912152852863f, 0.00014910359459463507f, 0.0001812049449654296f, 0.0001478178019169718f, 0.0001058969137375243f, 0.00023526750737801194f, 0.0002589242940302938f, 0.00011915280629182234f, 0.00026129395700991154f, 0.00015752189210616052f, 0.00015781568072270602f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #40 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0074790362268686295f, 0.007825134322047234f, 0.009052365086972713f, 0.007775293663144112f, 0.008907482959330082f, 0.006568432319909334f, 0.004284854978322983f, 0.00865640863776207f, 0.006555523257702589f, 0.0046134465374052525f, 0.010221103206276894f, 0.006544788368046284f, 0.007106674835085869f, 0.0073097082786262035f, 0.00764884939417243f, 0.00553171057254076f, 0.004440345335751772f, 0.010225438512861729f, 0.006860951893031597f, 0.008190092630684376f, 0.008340314961969852f, 0.006271059159189463f, 0.007299742661416531f, 0.00868908315896988f, 0.007543248124420643f, 0.005621475633233786f, 0.006576996762305498f, 0.0062186578288674355f, 0.005932051222771406f, 0.007269054185599089f, 0.006952989846467972f, 0.006938531529158354f, 0.009487324394285679f, 0.008282572031021118f, 0.009942256845533848f, 0.009287563152611256f, 0.007088724058121443f, 0.009296257980167866f, 0.006125291809439659f, 0.005866297520697117f, 0.007017933763563633f, 0.00461691664531827f, 0.009809453040361404f, 0.008107435889542103f, 0.007127763237804174f, 0.006142488215118647f, 0.0058812666684389114f, 0.005940223578363657f, 0.007255402859300375f, 0.007471670396625996f, 0.007102360017597675f, 0.005335972644388676f, 0.005844706203788519f, 0.005639287643134594f, 0.006336902733892202f, 0.007701209746301174f, 0.0062822564505040646f, 0.0045006186701357365f, 0.009998869150876999f, 0.011004282161593437f, 0.005063994321972132f, 0.011104993522167206f, 0.006694680079817772f, 0.006707166321575642f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #41 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.252648694906384e-05f, 7.13963236194104e-05f, 7.639980321982875e-05f, 7.7753298683092e-05f, 7.646047015441582e-05f, 6.401567225111648e-05f, 7.599381933687255e-05f, 7.896628812886775e-05f, 7.782376633258536e-05f, 7.427833043038845e-05f, 7.097552588675171e-05f, 6.288258009590209e-05f, 9.414239320904016e-05f, 6.732931069564074e-05f, 6.123220373410732e-05f, 6.33687450317666e-05f, 6.380565173458308e-05f, 6.099504389567301e-05f, 8.966343011707067e-05f, 7.298136915778741e-05f, 8.075327059486881e-05f, 6.827321340097114e-05f, 8.224025077652186e-05f, 7.613209163537249e-05f, 5.75768317503389e-05f, 8.251355757238343e-05f, 7.00973832863383e-05f, 7.687358447583392e-05f, 0.00011381701187929139f, 6.338053935905918e-05f, 6.590816337848082e-05f, 7.789606024743989e-05f, 7.543778338003904e-05f, 8.611002704128623e-05f, 5.421523019322194e-05f, 5.5166274250950664e-05f, 7.590098539367318e-05f, 6.525488424813375e-05f, 6.229399150470272e-05f, 7.812349940650165e-05f, 5.852694812347181e-05f, 8.832182356854901e-05f, 7.463694055331871e-05f, 6.956316065043211e-05f, 8.611270459368825e-05f, 6.54643663438037e-05f, 5.3444007789948955e-05f, 7.17998409527354e-05f, 8.847406570566818e-05f, 7.881169585743919e-05f, 7.160458335420117e-05f, 0.00010340395965613425f, 8.605446782894433e-05f, 0.00011371573782525957f, 6.78223223076202e-05f, 6.750290049239993e-05f, 7.153280603233725e-05f, 8.527800673618913e-05f, 8.043194247875363e-05f, 6.275014311540872e-05f, 6.832408689660951e-05f, 7.907226245151833e-05f, 7.204939174698666e-05f, 8.072012133197859e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #42 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003507375717163086f, 0.003034343710169196f, 0.00324699142947793f, 0.0033045150339603424f, 0.003249569796025753f, 0.002720666117966175f, 0.0032297372817993164f, 0.003356067230924964f, 0.003307509934529662f, 0.0031568289268761873f, 0.0030164597555994987f, 0.0026725095231086016f, 0.004001051653176546f, 0.0028614955954253674f, 0.0026023685932159424f, 0.002693171612918377f, 0.0027117400895804167f, 0.0025922893546521664f, 0.003810695605352521f, 0.003101708134636283f, 0.003432014025747776f, 0.0029016113840043545f, 0.003495210548862815f, 0.0032356136944144964f, 0.0024470153730362654f, 0.003506826236844063f, 0.0029791388660669327f, 0.0032671273220330477f, 0.00483722286298871f, 0.0026936728972941637f, 0.0028010967653244734f, 0.0033105826005339622f, 0.0032061056699603796f, 0.0036596760619431734f, 0.00230414723046124f, 0.0023445666301995516f, 0.0032257919665426016f, 0.002773332642391324f, 0.002647494664415717f, 0.0033202485647052526f, 0.002487395191565156f, 0.003753677476197481f, 0.003172069787979126f, 0.0029564343858510256f, 0.00365978991612792f, 0.002782235387712717f, 0.0022713702637702227f, 0.0030514930840581656f, 0.003760147839784622f, 0.0033494969829916954f, 0.003043194767087698f, 0.0043946681544184685f, 0.0036573149263858795f, 0.004832918755710125f, 0.0028824484907090664f, 0.002868873067200184f, 0.003040144219994545f, 0.0036243151407688856f, 0.003418357577174902f, 0.002666881075128913f, 0.002903773682191968f, 0.0033605711068958044f, 0.0030620992183685303f, 0.0034306051675230265f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #43 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00023025127302389592f, 0.0001224102743435651f, 0.00016052534920163453f, 0.00018879050912801176f, 0.00012036782572977245f, 0.0001614914508536458f, 0.00012124169006710872f, 8.050900942180306e-05f, 0.00017581257270649076f, 9.878486162051558e-05f, 0.0001484467793488875f, 0.00016856410366017371f, 0.0001292790548177436f, 0.00010048272088170052f, 0.00024339609080925584f, 0.00016707017493899912f, 0.00018470232316758484f, 0.0002877992228604853f, 0.00020169949857518077f, 0.00018204785010311753f, 0.00016529623826500028f, 0.00019356598204467446f, 0.00010299121640855446f, 0.00014256768918130547f, 0.00016058588516898453f, 0.00011305820953566581f, 0.00012540255556814373f, 0.00020396274339873344f, 8.564479503547773e-05f, 0.00017381669022142887f, 0.00014017564535606652f, 0.00025953867589123547f, 0.00010405706416349858f, 0.0001564119738759473f, 0.00013761987793259323f, 0.00013758940622210503f, 0.0002561402798164636f, 0.00015479879220947623f, 0.00022221785911824554f, 0.0001864546211436391f, 0.00018599651230033487f, 0.0001250701316166669f, 0.00013698125258088112f, 0.0001884434896055609f, 0.00018319441005587578f, 0.00011022327817045152f, 0.00022729087504558265f, 0.0001859423064161092f, 0.0001628165045985952f, 0.00021559445303864777f, 0.00014002926764078438f, 0.000145001889904961f, 0.0001153228513430804f, 0.00017408093845006078f, 0.00025563305825926363f, 0.00013387778017204255f, 0.00010700129496399313f, 0.0002279888722114265f, 0.00010154661868000403f, 0.00018282233213540167f, 0.00014563725562766194f, 0.000179761802428402f, 0.0001342560281045735f, 0.0001618188398424536f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009785679168999195f, 0.005202436354011297f, 0.006822327151894569f, 0.008023596368730068f, 0.0051156324334442616f, 0.006863386835902929f, 0.005152771715074778f, 0.003421632805839181f, 0.007472034078091383f, 0.004198356531560421f, 0.006308987736701965f, 0.007163974456489086f, 0.005494359415024519f, 0.004270515404641628f, 0.010344333946704865f, 0.007100482005625963f, 0.007849848829209805f, 0.012231466360390186f, 0.008572228252887726f, 0.007737033534795046f, 0.007025090046226978f, 0.008226553909480572f, 0.004377126693725586f, 0.006059126928448677f, 0.006824899930506945f, 0.0048049739561975f, 0.005329608451575041f, 0.008668416179716587f, 0.0036399036180227995f, 0.007387209217995405f, 0.005957464687526226f, 0.011030393652617931f, 0.004422425292432308f, 0.006647508591413498f, 0.005848844535648823f, 0.00584754953160882f, 0.010885961353778839f, 0.006578948814421892f, 0.009444259107112885f, 0.007924321107566357f, 0.00790485180914402f, 0.005315480288118124f, 0.005821703001856804f, 0.008008847944438457f, 0.007785762194544077f, 0.004684489220380783f, 0.009659862145781517f, 0.007902547717094421f, 0.006919701583683491f, 0.009162764064967632f, 0.005951243452727795f, 0.006162580102682114f, 0.0049012210220098495f, 0.007398440036922693f, 0.01086440496146679f, 0.005689805373549461f, 0.00454755499958992f, 0.00968952663242817f, 0.00431573111563921f, 0.007769948802888393f, 0.006189583335071802f, 0.007639876566827297f, 0.005705880932509899f, 0.0068773007951676846f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #45 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.003230712143704e-05f, 8.478460949845612e-05f, 6.669462163699791e-05f, 5.303745638229884e-05f, 7.216305675683543e-05f, 6.788534665247425e-05f, 8.175546827260405e-05f, 8.925292786443606e-05f, 6.10600909567438e-05f, 6.292750913416967e-05f, 6.46492771920748e-05f, 6.779001705581322e-05f, 8.557282126275823e-05f, 7.155505591072142e-05f, 5.35415492777247e-05f, 9.645658428780735e-05f, 8.14866361906752e-05f, 7.90834310464561e-05f, 5.296229574014433e-05f, 7.10853491909802e-05f, 5.728660471504554e-05f, 6.138392927823588e-05f, 6.395503442035988e-05f, 7.196237129392102e-05f, 9.432735532755032e-05f, 9.373662032885477e-05f, 5.759182386100292e-05f, 6.329266034299508e-05f, 0.00010310786456102505f, 7.363972690654919e-05f, 7.619485404575244e-05f, 6.322460831142962e-05f, 8.209460793295875e-05f, 6.546881195390597e-05f, 8.87450369191356e-05f, 7.141660898923874e-05f, 5.77118516957853e-05f, 7.491040014429018e-05f, 8.409995643887669e-05f, 6.44942483631894e-05f, 7.223018474178389e-05f, 6.0653073887806386e-05f, 8.400435035582632e-05f, 6.246171687962487e-05f, 9.019846038427204e-05f, 7.583255501231179e-05f, 6.852713704574853e-05f, 6.610941636608914e-05f, 6.897775892866775e-05f, 8.566829637857154e-05f, 7.331939559662715e-05f, 6.87436040607281e-05f, 8.120739948935807e-05f, 6.117505836300552e-05f, 5.1716640882659703e-05f, 6.752710760338232e-05f, 7.60474504204467e-05f, 6.432358350139111e-05f, 9.510212839813903e-05f, 6.11093855695799e-05f, 8.013199840206653e-05f, 6.42892555333674e-05f, 7.04130798112601e-05f, 7.107146666385233e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #46 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0029763730708509684f, 0.003603345947340131f, 0.002834521234035492f, 0.002254091901704669f, 0.003066929755732417f, 0.002885127207264304f, 0.003474607365205884f, 0.003793249372392893f, 0.0025950537528842688f, 0.002674418967217207f, 0.002747594378888607f, 0.002881075721234083f, 0.003636844689026475f, 0.0030410897452384233f, 0.00227551581338048f, 0.004099404904991388f, 0.0034631818998605013f, 0.003361045615747571f, 0.002250897465273738f, 0.003021127311512828f, 0.0024346807040274143f, 0.00260881707072258f, 0.0027180889155715704f, 0.0030584007035940886f, 0.004008912481367588f, 0.003983806353062391f, 0.0024476523976773024f, 0.002689938060939312f, 0.004382084123790264f, 0.003129688324406743f, 0.003238281235098839f, 0.0026870458386838436f, 0.0034890207462012768f, 0.002782424446195364f, 0.0037716638762503862f, 0.0030352058820426464f, 0.0024527537170797586f, 0.003183691995218396f, 0.0035742479376494884f, 0.002741005504503846f, 0.0030697828624397516f, 0.0025777556002140045f, 0.0035701848100870848f, 0.002654623007401824f, 0.003833434544503689f, 0.0032228834461420774f, 0.002912403317168355f, 0.0028096502646803856f, 0.0029315545689314604f, 0.0036409024614840746f, 0.003116074251011014f, 0.0029216031543910503f, 0.00345131428912282f, 0.002599939936771989f, 0.002197957132011652f, 0.0028699019458144903f, 0.003232016460970044f, 0.002733752364292741f, 0.004041840322315693f, 0.0025971487630158663f, 0.003405609866604209f, 0.002732293214648962f, 0.002992555731907487f, 0.003020537318661809f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #47 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00019241665722802281f, 0.00015747835277579725f, 0.00012983402120880783f, 0.00016403790505137295f, 0.00020776990277227014f, 0.00020025101548526436f, 0.00018777781224343926f, 0.00019861539476551116f, 0.00014652723621111363f, 0.0001880020136013627f, 0.00013671348278876394f, 0.00014507498417515308f, 0.00011773008736781776f, 0.0001819813478505239f, 0.0001442897046217695f, 0.00019686833547893912f, 0.0001653392391745001f, 0.00017380907956976444f, 0.00021982649923302233f, 0.00025549106067046523f, 0.00019629466987680644f, 0.00018660146452020854f, 0.00021949746587779373f, 0.00017045688582584262f, 0.0002094399678753689f, 0.00024041914730332792f, 0.00019754841923713684f, 0.0001451496355002746f, 0.0002145578182535246f, 0.00012549731764011085f, 0.00015837432874832302f, 0.0001419151813024655f, 0.0001324048644164577f, 0.00016797534772194922f, 0.00016589545703027397f, 0.00019728881306946278f, 0.00014063420530874282f, 0.00019686805899254978f, 0.00016012578271329403f, 0.00014703044143971056f, 0.00014481715334113687f, 0.00018080508743878454f, 0.000193523577763699f, 0.0001348531513940543f, 0.00012137419980717823f, 0.00017818555352278054f, 0.0001420372282154858f, 0.00012023491581203416f, 0.000187447207281366f, 0.00015317040379159153f, 0.00016019637405406684f, 0.0001839854521676898f, 0.00023396179312840104f, 0.00024226437381003052f, 0.0001723078457871452f, 0.00018256368639413267f, 0.00020400069479364902f, 0.0001696989347692579f, 0.00021761443349532783f, 0.00017479747475590557f, 0.00014273964916355908f, 0.00013513259182218462f, 0.00022600946249440312f, 0.00023335317382588983f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008177707903087139f, 0.006692830007523298f, 0.005517945624887943f, 0.006971610710024834f, 0.008830220438539982f, 0.008510667830705643f, 0.007980557158589363f, 0.008441153913736343f, 0.006227407604455948f, 0.007990085519850254f, 0.005810323171317577f, 0.006165686994791031f, 0.005003528669476509f, 0.007734207436442375f, 0.006132312119007111f, 0.008366904221475124f, 0.007026917766779661f, 0.007386885583400726f, 0.009342625737190247f, 0.010858369991183281f, 0.008342523127794266f, 0.007930561900138855f, 0.009328641928732395f, 0.007244417443871498f, 0.008901198394596577f, 0.010217813774943352f, 0.008395807817578316f, 0.006168859079480171f, 0.009118706919252872f, 0.0053336359560489655f, 0.006730908993631601f, 0.006031394936144352f, 0.005627206526696682f, 0.007138952147215605f, 0.0070505570620298386f, 0.008384774439036846f, 0.0059769535437226295f, 0.008366892114281654f, 0.006805345881730318f, 0.006248793564736843f, 0.006154729053378105f, 0.0076842159032821655f, 0.00822475180029869f, 0.005731258541345596f, 0.005158403422683477f, 0.007572885602712631f, 0.006036581937223673f, 0.005109983962029219f, 0.00796650629490614f, 0.006509742233902216f, 0.0068083456717431545f, 0.007819381542503834f, 0.009943376295268536f, 0.010296235792338848f, 0.007323083002120256f, 0.007758956402540207f, 0.008670029230415821f, 0.007212204392999411f, 0.009248613379895687f, 0.00742889242246747f, 0.006066435016691685f, 0.00574313523247838f, 0.009605402126908302f, 0.009917509742081165f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #49 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00010125669359695166f, 9.099220915231854e-05f, 9.085539932129905e-05f, 5.757541293860413e-05f, 6.856919935671613e-05f, 7.951503357617185e-05f, 6.591105193365365e-05f, 0.00012055831757606938f, 6.763781129848212e-05f, 8.372279262403026e-05f, 6.632001168327406e-05f, 9.43118502618745e-05f, 7.952618761919439e-05f, 5.995735409669578e-05f, 8.619699656264856e-05f, 8.426613203482702e-05f, 6.679358921246603e-05f, 8.40840584714897e-05f, 7.232373172882944e-05f, 6.410454807337373e-05f, 6.925023626536131e-05f, 9.358370152767748e-05f, 8.708965469850227e-05f, 0.00010380087769590318f, 7.579769589938223e-05f, 5.756515383836813e-05f, 8.467257430311292e-05f, 0.00012218483607284725f, 6.917116115801036e-05f, 6.243528332561255e-05f, 6.98481744620949e-05f, 0.00010232345812255517f, 9.849607158685103e-05f, 0.0001129455995396711f, 5.7894725614460185e-05f, 0.00011461471876828f, 7.495075260521844e-05f, 9.746745490701869e-05f, 9.201408101944253e-05f, 8.472722402075306e-05f, 6.619920168304816e-05f, 7.10135354893282e-05f, 7.370654930127785e-05f, 7.283607556018978e-05f, 9.587978274794295e-05f, 8.572734805056825e-05f, 8.377139602089301e-05f, 6.279797526076436e-05f, 7.690079655731097e-05f, 8.770959539106116e-05f, 6.130625115474686e-05f, 7.075443136272952e-05f, 6.668708374490961e-05f, 8.001419337233528e-05f, 6.76372364978306e-05f, 9.581405174685642e-05f, 8.108389738481492e-05f, 7.910706335678697e-05f, 7.227406604215503e-05f, 0.00010632770863594487f, 8.515640365658328e-05f, 8.80494189914316e-05f, 6.177971954457462e-05f, 6.237638444872573e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #50 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00430340925231576f, 0.003867168677970767f, 0.0038613544311374426f, 0.002446955069899559f, 0.0029141909908503294f, 0.003379388712346554f, 0.0028012196999043226f, 0.005123728420585394f, 0.0028746069874614477f, 0.003558218479156494f, 0.002818600507453084f, 0.004008253570646048f, 0.0033798629883676767f, 0.002548187505453825f, 0.0036633722484111786f, 0.003581310622394085f, 0.0028387275524437428f, 0.003573572263121605f, 0.003073758678510785f, 0.002724443329498172f, 0.002943134866654873f, 0.003977307118475437f, 0.003701310371980071f, 0.004411537200212479f, 0.003221401944756508f, 0.0024465189781039953f, 0.0035985843278467655f, 0.0051928553730249405f, 0.0029397744219750166f, 0.002653499599546194f, 0.002968547400087118f, 0.004348746966570616f, 0.004186083097010851f, 0.004800187889486551f, 0.0024605258367955685f, 0.00487112533301115f, 0.0031854070257395506f, 0.0041423668153584f, 0.00391059834510088f, 0.003600906813517213f, 0.002813466126099229f, 0.0030180751346051693f, 0.003132528392598033f, 0.0030955332331359386f, 0.00407489063218236f, 0.0036434121429920197f, 0.0035602841526269913f, 0.002668913919478655f, 0.0032682837918400764f, 0.0037276577204465866f, 0.0026055157650262117f, 0.003007063176482916f, 0.002834201091900468f, 0.003400603076443076f, 0.002874582540243864f, 0.004072097130119801f, 0.0034460655879229307f, 0.0033620502799749374f, 0.003071647835895419f, 0.004518927540630102f, 0.0036191469989717007f, 0.003742100205272436f, 0.0026256379205733538f, 0.0026509964372962713f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #51 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002005157875828445f, 0.00021990604000166059f, 0.00018670616555027664f, 0.00014960046974010766f, 0.00024296464107465f, 0.00040396334952674806f, 0.000331964431097731f, 0.0001977272768272087f, 0.00018625386292114854f, 0.00042348308488726616f, 0.0003029350482393056f, 0.00023443180543836206f, 0.00017147093603853136f, 0.000279028172371909f, 0.0003450963704381138f, 0.00013297662371769547f, 0.00014213596296031028f, 8.287116361316293e-05f, 0.00021607422968372703f, 0.0003518263984005898f, 0.00033795140916481614f, 0.00017610342183616012f, 0.00021338382794056088f, 0.00020139165280852467f, 0.000174883782165125f, 0.00013216947263572365f, 0.00034084898652508855f, 0.00016585280536673963f, 0.00024826315348036587f, 0.0003724854323081672f, 0.0003147749521303922f, 0.00036054672091268003f, 0.0003143728827126324f, 0.00022209057351574302f, 0.00027735313051380217f, 0.0004757276037707925f, 0.00017755561566445976f, 0.00045500375563278794f, 0.00022502859064843506f, 0.0003328196471557021f, 0.0004571655299514532f, 0.00023406834225170314f, 9.659767965786159e-05f, 0.00022891786647960544f, 0.00033383406116627157f, 0.00026667435304261744f, 0.00018558598821982741f, 0.0003225306863896549f, 0.0001867583632702008f, 0.00029845096287317574f, 0.0004302027227822691f, 0.0005002196412533522f, 0.00025065915542654693f, 0.00022046579397283494f, 0.0003554587601684034f, 0.00018941814778372645f, 0.00018030621868092567f, 0.00021040932915639132f, 0.00033313038875348866f, 0.0001900919887702912f, 0.00011153949162689969f, 0.00013221404515206814f, 0.00019817863358184695f, 0.00036790428566746414f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #52 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008521921001374722f, 0.0093460064381361f, 0.007935011759400368f, 0.006358019541949034f, 0.01032599713653326f, 0.0171684417873621f, 0.014108488336205482f, 0.008403409272432327f, 0.007915789261460304f, 0.01799803040921688f, 0.012874739244580269f, 0.009963351301848888f, 0.007287514396011829f, 0.011858697049319744f, 0.014666595496237278f, 0.005651506595313549f, 0.00604077847674489f, 0.003522024489939213f, 0.009183154441416264f, 0.014952621422708035f, 0.014362934976816177f, 0.007484395056962967f, 0.009068812243640423f, 0.008559145033359528f, 0.0074325609020888805f, 0.0056172022596001625f, 0.014486081898212433f, 0.0070487442426383495f, 0.010551183484494686f, 0.01583063043653965f, 0.013377935625612736f, 0.015323235653340816f, 0.013360847719013691f, 0.009438849054276943f, 0.011787507683038712f, 0.020218422636389732f, 0.007546113338321447f, 0.01933765970170498f, 0.009563715197145939f, 0.014144835062325f, 0.019429534673690796f, 0.009947904385626316f, 0.00410540122538805f, 0.009729009121656418f, 0.0141879478469491f, 0.011333659291267395f, 0.007887404412031174f, 0.013707553967833519f, 0.007937230169773102f, 0.012684165500104427f, 0.01828361488878727f, 0.021259333938360214f, 0.010653014294803143f, 0.009369796141982079f, 0.015106997452676296f, 0.008050271309912205f, 0.007663014344871044f, 0.008942396380007267f, 0.014158041216433048f, 0.00807890947908163f, 0.004740428179502487f, 0.00561909656971693f, 0.008422591723501682f, 0.015635931864380836f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #53 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.969660509843379e-05f, 0.00012248668645042926f, 8.811609586700797e-05f, 6.463519093813375e-05f, 8.467110455967486e-05f, 9.392220817971975e-05f, 0.0001552051689941436f, 8.798750786809251e-05f, 8.756641182117164e-05f, 8.020699169719592e-05f, 9.170362318400294e-05f, 0.00011710691615007818f, 7.019789336482063e-05f, 0.00010241299605695531f, 0.000127295425045304f, 8.355555473826826e-05f, 7.657286914763972e-05f, 7.545344124082476e-05f, 9.252328163711354e-05f, 0.00011869655281770974f, 8.233670814661309e-05f, 9.53463968471624e-05f, 8.975288073997945e-05f, 8.576373511459678e-05f, 0.00011917028314201161f, 7.013449794612825e-05f, 7.150223245844245e-05f, 0.00010409099922981113f, 9.775980288395658e-05f, 5.995530591462739e-05f, 8.547669131075963e-05f, 8.271675324067473e-05f, 9.043190948432311e-05f, 9.981065522879362e-05f, 9.109238453675061e-05f, 8.950100163929164e-05f, 0.00011254759738221765f, 9.170347766485065e-05f, 9.077593131223693e-05f, 0.00010625547292875126f, 7.319456926779822e-05f, 8.08397016953677e-05f, 8.856000931700692e-05f, 0.00015254106256179512f, 0.00014548002218361944f, 6.353498611133546e-05f, 0.00010902247595367953f, 6.175995076773688e-05f, 0.0001062035807990469f, 9.413941006641835e-05f, 0.00014424593246076256f, 6.82523605064489e-05f, 0.0001047183177433908f, 8.56752012623474e-05f, 0.00012795458314940333f, 7.042801735224202e-05f, 0.00013716380635742098f, 0.0001356749708065763f, 9.88480169326067e-05f, 7.118745270418003e-05f, 7.974996697157621e-05f, 8.766038081375882e-05f, 9.78339885477908e-05f, 0.00012673732999246567f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #54 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0033871056511998177f, 0.005205684341490269f, 0.0037449339870363474f, 0.0027469955384731293f, 0.0035985219292342663f, 0.00399169372394681f, 0.006596219260245562f, 0.0037394689861685038f, 0.003721572458744049f, 0.0034087970852851868f, 0.003897403832525015f, 0.004977043718099594f, 0.0029834103770554066f, 0.004352552350610495f, 0.005410055164247751f, 0.0035511108580976725f, 0.0032543467823415995f, 0.003206771332770586f, 0.0039322394877672195f, 0.005044603254646063f, 0.0034993099980056286f, 0.004052221775054932f, 0.0038144972641021013f, 0.0036449586041271687f, 0.005064737051725388f, 0.002980716060847044f, 0.0030388447921723127f, 0.0044238674454391f, 0.0041547915898263454f, 0.0025481004267930984f, 0.0036327592097222805f, 0.003515461925417185f, 0.003843356156721711f, 0.004241952672600746f, 0.0038714262191206217f, 0.003803792642429471f, 0.004783272743225098f, 0.00389739777892828f, 0.0038579769898205996f, 0.004515857435762882f, 0.0031107692047953606f, 0.0034356871619820595f, 0.0037638002540916204f, 0.006482995115220547f, 0.006182901095598936f, 0.0027002368588000536f, 0.004633455071598291f, 0.0026247978676110506f, 0.004513652063906193f, 0.004000924993306398f, 0.0061304522678256035f, 0.002900725230574608f, 0.004450528416782618f, 0.0036411958280950785f, 0.005438069812953472f, 0.002993190661072731f, 0.005829461384564638f, 0.005766185931861401f, 0.004201040603220463f, 0.003025466576218605f, 0.00338937365449965f, 0.003725566202774644f, 0.004157944582402706f, 0.005386336240917444f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #55 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(4.787017314811237e-05f, 2.10084854188608e-05f, 7.063394150463864e-05f, 3.5383014619583264e-05f, 5.7042987464228645e-05f, 6.139417382655665e-05f, 4.605416688718833e-05f, 5.163933747098781e-05f, 3.9557857235195115e-05f, 3.870188083965331e-05f, 7.961371738929302e-05f, 0.00013252129429019988f, 5.1361159421503544e-05f, 9.906478953780606e-05f, 6.22823863523081e-05f, 6.219407077878714e-05f, 7.847454980947077e-05f, 6.712129834340885e-05f, 4.452621578820981e-05f, 8.869149314705282e-05f, 6.13760348642245e-05f, 7.354340050369501e-05f, 6.778743409086019e-05f, 9.830133058130741e-05f, 6.414635572582483e-05f, 6.118092278484255e-05f, 6.986520020291209e-05f, 8.670209354022518e-05f, 5.1522412832127884e-05f, 4.109077053726651e-05f, 4.877431274508126e-05f, 4.8680940381018445e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #56 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012206893414258957f, 0.005357163492590189f, 0.018011653795838356f, 0.00902266800403595f, 0.014545961283147335f, 0.0156555138528347f, 0.011743811890482903f, 0.0131680304184556f, 0.010087252594530582f, 0.009868979454040527f, 0.020301496610045433f, 0.033792927861213684f, 0.013097095303237438f, 0.025261519476771355f, 0.015882007777690887f, 0.015859486535191536f, 0.02001100964844227f, 0.01711593009531498f, 0.011354184709489346f, 0.022616328671574593f, 0.015650887042284012f, 0.018753565847873688f, 0.017285794019699097f, 0.025066837668418884f, 0.016357319429516792f, 0.015601133927702904f, 0.01781562529504299f, 0.022109031677246094f, 0.013138214126229286f, 0.010478145442903042f, 0.012437448836863041f, 0.012413638643920422f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #57 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(input_1_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #58 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conversion_0_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #59 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #60 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #61 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #62 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #63 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #64 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #65 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #66 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #67 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #68 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #69 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #70 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #71 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #72 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #73 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #74 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #75 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #76 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.010147771798074245f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #77 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_20_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10507936775684357f),
    AI_PACK_INTQ_ZP(-35)))

/* Int quant #78 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_21_fmt_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_UINTQ_ZP(0)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch2, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 16, 16), AI_STRIDE_INIT(4, 1, 1, 128, 2048),
  1, &conv2d_18_scratch2_array, &conv2d_18_scratch2_intq)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 16, 16), AI_STRIDE_INIT(4, 1, 1, 128, 2048),
  1, &conv2d_18_scratch1_array, &conv2d_18_scratch1_intq)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_18_scratch0_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 16, 16), AI_STRIDE_INIT(4, 1, 1, 128, 2048),
  1, &conv2d_17_scratch1_array, &conv2d_17_scratch1_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_17_scratch0_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 16, 16), AI_STRIDE_INIT(4, 1, 1, 128, 2048),
  1, &conv2d_16_scratch1_array, &conv2d_16_scratch1_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_16_scratch0_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 16, 16), AI_STRIDE_INIT(4, 1, 1, 128, 2048),
  1, &conv2d_15_scratch1_array, &conv2d_15_scratch1_intq)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_15_scratch0_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 16, 16), AI_STRIDE_INIT(4, 1, 1, 128, 2048),
  1, &conv2d_14_scratch1_array, &conv2d_14_scratch1_intq)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1792, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1792, 1792),
  1, &conv2d_14_scratch0_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 16, 16), AI_STRIDE_INIT(4, 1, 1, 128, 2048),
  1, &conv2d_13_scratch1_array, &conv2d_13_scratch1_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_13_scratch0_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 16, 16), AI_STRIDE_INIT(4, 1, 1, 128, 2048),
  1, &conv2d_12_scratch1_array, &conv2d_12_scratch1_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_12_scratch0_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_11_scratch1_array, &conv2d_11_scratch1_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 2369, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2369, 2369),
  1, &conv2d_11_scratch0_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_10_scratch1_array, &conv2d_10_scratch1_intq)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 896, 1, 1), AI_STRIDE_INIT(4, 1, 1, 896, 896),
  1, &conv2d_10_scratch0_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_9_scratch1_array, &conv2d_9_scratch1_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 2369, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2369, 2369),
  1, &conv2d_9_scratch0_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_8_scratch1_array, &conv2d_8_scratch1_intq)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 896, 1, 1), AI_STRIDE_INIT(4, 1, 1, 896, 896),
  1, &conv2d_8_scratch0_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_7_scratch1_array, &conv2d_7_scratch1_intq)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 2369, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2369, 2369),
  1, &conv2d_7_scratch0_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_6_scratch1_array, &conv2d_6_scratch1_intq)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 896, 1, 1), AI_STRIDE_INIT(4, 1, 1, 896, 896),
  1, &conv2d_6_scratch0_array, NULL)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_5_scratch1_array, &conv2d_5_scratch1_intq)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 2369, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2369, 2369),
  1, &conv2d_5_scratch0_array, NULL)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_4_scratch1_array, &conv2d_4_scratch1_intq)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 896, 1, 1), AI_STRIDE_INIT(4, 1, 1, 896, 896),
  1, &conv2d_4_scratch0_array, NULL)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_3_scratch1_array, &conv2d_3_scratch1_intq)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 2369, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2369, 2369),
  1, &conv2d_3_scratch0_array, NULL)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_2_scratch1_array, &conv2d_2_scratch1_intq)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 768, 1, 1), AI_STRIDE_INIT(4, 1, 1, 768, 768),
  1, &conv2d_2_scratch0_array, NULL)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 16, 16), AI_STRIDE_INIT(4, 1, 1, 32, 512),
  1, &conv2d_1_scratch1_array, &conv2d_1_scratch1_intq)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 2284, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2284, 2284),
  1, &conv2d_1_scratch0_array, NULL)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  dense_20_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &dense_20_bias_array, &dense_20_bias_intq)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  dense_20_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 10, 1, 1), AI_STRIDE_INIT(4, 1, 128, 1280, 1280),
  1, &dense_20_weights_array, &dense_20_weights_intq)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_18_bias_array, &conv2d_18_bias_intq)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_18_weights_array, &conv2d_18_weights_intq)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_17_bias_array, &conv2d_17_bias_intq)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_17_weights_array, &conv2d_17_weights_intq)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_16_bias_array, &conv2d_16_bias_intq)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_16_weights_array, &conv2d_16_weights_intq)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_15_bias_array, &conv2d_15_bias_intq)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_15_weights_array, &conv2d_15_weights_intq)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_14_bias_array, &conv2d_14_bias_intq)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_14_weights_array, &conv2d_14_weights_intq)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_13_bias_array, &conv2d_13_bias_intq)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_13_weights_array, &conv2d_13_weights_intq)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_12_bias_array, &conv2d_12_bias_intq)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 1, 1, 128), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &conv2d_12_weights_array, &conv2d_12_weights_intq)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_11_bias_array, &conv2d_11_bias_intq)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 3, 3, 1), AI_STRIDE_INIT(4, 1, 64, 192, 576),
  1, &conv2d_11_weights_array, &conv2d_11_weights_intq)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_10_bias_array, &conv2d_10_bias_intq)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 1, 1, 64), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &conv2d_10_weights_array, &conv2d_10_weights_intq)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_9_bias_array, &conv2d_9_bias_intq)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 3, 3, 1), AI_STRIDE_INIT(4, 1, 64, 192, 576),
  1, &conv2d_9_weights_array, &conv2d_9_weights_intq)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_8_bias_array, &conv2d_8_bias_intq)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 1, 1, 64), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &conv2d_8_weights_array, &conv2d_8_weights_intq)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_7_bias_array, &conv2d_7_bias_intq)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 3, 3, 1), AI_STRIDE_INIT(4, 1, 64, 192, 576),
  1, &conv2d_7_weights_array, &conv2d_7_weights_intq)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_6_bias_array, &conv2d_6_bias_intq)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 1, 1, 64), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &conv2d_6_weights_array, &conv2d_6_weights_intq)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_5_bias_array, &conv2d_5_bias_intq)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 3, 3, 1), AI_STRIDE_INIT(4, 1, 64, 192, 576),
  1, &conv2d_5_weights_array, &conv2d_5_weights_intq)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_4_bias_array, &conv2d_4_bias_intq)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 1, 1, 64), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &conv2d_4_weights_array, &conv2d_4_weights_intq)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_3_bias_array, &conv2d_3_bias_intq)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 3, 3, 1), AI_STRIDE_INIT(4, 1, 64, 192, 576),
  1, &conv2d_3_weights_array, &conv2d_3_weights_intq)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_2_bias_array, &conv2d_2_bias_intq)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 1, 64), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_2_weights_array, &conv2d_2_weights_intq)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_1_bias_array, &conv2d_1_bias_intq)

/* Tensor #74 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 3, 3, 3, 32), AI_STRIDE_INIT(4, 1, 3, 9, 27),
  1, &conv2d_1_weights_array, &conv2d_1_weights_intq)

/* Tensor #75 */
AI_TENSOR_OBJ_DECLARE(
  input_1_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 32, 32), AI_STRIDE_INIT(4, 1, 1, 3, 96),
  1, &input_1_output_array, &input_1_output_intq)

/* Tensor #76 */
AI_TENSOR_OBJ_DECLARE(
  conversion_0_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 32, 32), AI_STRIDE_INIT(4, 1, 1, 3, 96),
  1, &conversion_0_output_array, &conversion_0_output_intq)

/* Tensor #77 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 16, 16), AI_STRIDE_INIT(4, 1, 1, 32, 512),
  1, &conv2d_1_output_array, &conv2d_1_output_intq)

/* Tensor #78 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_2_output_array, &conv2d_2_output_intq)

/* Tensor #79 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_3_output_array, &conv2d_3_output_intq)

/* Tensor #80 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_4_output_array, &conv2d_4_output_intq)

/* Tensor #81 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_5_output_array, &conv2d_5_output_intq)

/* Tensor #82 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_6_output_array, &conv2d_6_output_intq)

/* Tensor #83 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_7_output_array, &conv2d_7_output_intq)

/* Tensor #84 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_8_output_array, &conv2d_8_output_intq)

/* Tensor #85 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_9_output_array, &conv2d_9_output_intq)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_10_output_array, &conv2d_10_output_intq)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_11_output_array, &conv2d_11_output_intq)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 16, 16), AI_STRIDE_INIT(4, 1, 1, 128, 2048),
  1, &conv2d_12_output_array, &conv2d_12_output_intq)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 16, 16), AI_STRIDE_INIT(4, 1, 1, 128, 2048),
  1, &conv2d_13_output_array, &conv2d_13_output_intq)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 16, 16), AI_STRIDE_INIT(4, 1, 1, 128, 2048),
  1, &conv2d_14_output_array, &conv2d_14_output_intq)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 16, 16), AI_STRIDE_INIT(4, 1, 1, 128, 2048),
  1, &conv2d_15_output_array, &conv2d_15_output_intq)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 16, 16), AI_STRIDE_INIT(4, 1, 1, 128, 2048),
  1, &conv2d_16_output_array, &conv2d_16_output_intq)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 16, 16), AI_STRIDE_INIT(4, 1, 1, 128, 2048),
  1, &conv2d_17_output_array, &conv2d_17_output_intq)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &conv2d_18_output_array, &conv2d_18_output_intq)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  dense_20_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 1, 1, 10, 10),
  1, &dense_20_output_array, &dense_20_output_intq)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  dense_20_fmt_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &dense_20_fmt_output_array, NULL)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  nl_21_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &nl_21_output_array, NULL)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  nl_21_fmt_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 1, 1, 10, 10),
  1, &nl_21_fmt_output_array, &nl_21_fmt_output_intq)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_0_layer, 0,
  NL_TYPE,
  nl, node_convert_integer,
  &AI_NET_OBJ_INSTANCE, &conv2d_1_layer, AI_STATIC,
  .tensors = &conversion_0_chain, 
)


AI_STATIC_CONST ai_i8 conv2d_1_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_1_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_1_nl_params_data, conv2d_1_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_1_weights, &conv2d_1_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_1_scratch0, &conv2d_1_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_1_layer, 1,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_2_layer, AI_STATIC,
  .tensors = &conv2d_1_chain, 
  .groups = 1, 
  .nl_params = &conv2d_1_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)


AI_STATIC_CONST ai_i8 conv2d_2_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_2_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_2_nl_params_data, conv2d_2_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_2_weights, &conv2d_2_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_2_scratch0, &conv2d_2_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_layer, 2,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_3_layer, AI_STATIC,
  .tensors = &conv2d_2_chain, 
  .groups = 1, 
  .nl_params = &conv2d_2_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_i8 conv2d_3_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_3_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_3_nl_params_data, conv2d_3_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_3_weights, &conv2d_3_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_3_scratch0, &conv2d_3_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_3_layer, 3,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_4_layer, AI_STATIC,
  .tensors = &conv2d_3_chain, 
  .groups = 64, 
  .nl_params = &conv2d_3_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 conv2d_4_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_4_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_4_nl_params_data, conv2d_4_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_4_weights, &conv2d_4_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_4_scratch0, &conv2d_4_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_4_layer, 4,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_5_layer, AI_STATIC,
  .tensors = &conv2d_4_chain, 
  .groups = 1, 
  .nl_params = &conv2d_4_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_i8 conv2d_5_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_5_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_5_nl_params_data, conv2d_5_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_5_weights, &conv2d_5_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_5_scratch0, &conv2d_5_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_5_layer, 5,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_6_layer, AI_STATIC,
  .tensors = &conv2d_5_chain, 
  .groups = 64, 
  .nl_params = &conv2d_5_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 conv2d_6_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_6_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_6_nl_params_data, conv2d_6_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_6_weights, &conv2d_6_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_6_scratch0, &conv2d_6_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_6_layer, 6,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_7_layer, AI_STATIC,
  .tensors = &conv2d_6_chain, 
  .groups = 1, 
  .nl_params = &conv2d_6_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_i8 conv2d_7_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_7_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_7_nl_params_data, conv2d_7_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_7_weights, &conv2d_7_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_7_scratch0, &conv2d_7_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_7_layer, 7,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_8_layer, AI_STATIC,
  .tensors = &conv2d_7_chain, 
  .groups = 64, 
  .nl_params = &conv2d_7_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 conv2d_8_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_8_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_8_nl_params_data, conv2d_8_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_8_weights, &conv2d_8_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_8_scratch0, &conv2d_8_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_8_layer, 8,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_9_layer, AI_STATIC,
  .tensors = &conv2d_8_chain, 
  .groups = 1, 
  .nl_params = &conv2d_8_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_i8 conv2d_9_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_9_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_9_nl_params_data, conv2d_9_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_9_weights, &conv2d_9_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_9_scratch0, &conv2d_9_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_9_layer, 9,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_10_layer, AI_STATIC,
  .tensors = &conv2d_9_chain, 
  .groups = 64, 
  .nl_params = &conv2d_9_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 conv2d_10_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_10_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_10_nl_params_data, conv2d_10_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_10_weights, &conv2d_10_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_10_scratch0, &conv2d_10_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_10_layer, 10,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_11_layer, AI_STATIC,
  .tensors = &conv2d_10_chain, 
  .groups = 1, 
  .nl_params = &conv2d_10_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_i8 conv2d_11_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_11_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_11_nl_params_data, conv2d_11_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_11_weights, &conv2d_11_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_11_scratch0, &conv2d_11_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_11_layer, 11,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_12_layer, AI_STATIC,
  .tensors = &conv2d_11_chain, 
  .groups = 64, 
  .nl_params = &conv2d_11_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 conv2d_12_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_12_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_12_nl_params_data, conv2d_12_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_12_weights, &conv2d_12_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_12_scratch0, &conv2d_12_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_12_layer, 12,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_13_layer, AI_STATIC,
  .tensors = &conv2d_12_chain, 
  .groups = 1, 
  .nl_params = &conv2d_12_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_i8 conv2d_13_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_13_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_13_nl_params_data, conv2d_13_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_13_weights, &conv2d_13_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_13_scratch0, &conv2d_13_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_13_layer, 13,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_14_layer, AI_STATIC,
  .tensors = &conv2d_13_chain, 
  .groups = 128, 
  .nl_params = &conv2d_13_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 conv2d_14_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_14_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_14_nl_params_data, conv2d_14_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_14_weights, &conv2d_14_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_14_scratch0, &conv2d_14_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_14_layer, 14,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_15_layer, AI_STATIC,
  .tensors = &conv2d_14_chain, 
  .groups = 1, 
  .nl_params = &conv2d_14_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_i8 conv2d_15_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_15_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_15_nl_params_data, conv2d_15_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_15_weights, &conv2d_15_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_15_scratch0, &conv2d_15_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_15_layer, 15,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_16_layer, AI_STATIC,
  .tensors = &conv2d_15_chain, 
  .groups = 128, 
  .nl_params = &conv2d_15_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 conv2d_16_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_16_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_16_nl_params_data, conv2d_16_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_16_weights, &conv2d_16_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_16_scratch0, &conv2d_16_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_16_layer, 16,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_17_layer, AI_STATIC,
  .tensors = &conv2d_16_chain, 
  .groups = 1, 
  .nl_params = &conv2d_16_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_i8 conv2d_17_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_17_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_17_nl_params_data, conv2d_17_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_17_weights, &conv2d_17_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_17_scratch0, &conv2d_17_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_17_layer, 17,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_18_layer, AI_STATIC,
  .tensors = &conv2d_17_chain, 
  .groups = 128, 
  .nl_params = &conv2d_17_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 conv2d_18_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_18_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_18_nl_params_data, conv2d_18_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_18_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_18_weights, &conv2d_18_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_18_scratch0, &conv2d_18_scratch1, &conv2d_18_scratch2)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_18_layer, 18,
  OPTIMIZED_CONV2D_TYPE,
  conv2d_nl_pool, forward_conv2d_nl_pool_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &dense_20_layer, AI_STATIC,
  .tensors = &conv2d_18_chain, 
  .groups = 1, 
  .nl_params = &conv2d_18_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(16, 16), 
  .pool_stride = AI_SHAPE_2D_INIT(16, 16), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_ap_array_integer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_20_weights, &dense_20_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_20_layer, 20,
  DENSE_TYPE,
  dense, forward_dense_integer_SSSA,
  &AI_NET_OBJ_INSTANCE, &dense_20_fmt_layer, AI_STATIC,
  .tensors = &dense_20_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_20_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_20_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_20_fmt_layer, 20,
  NL_TYPE,
  nl, node_convert,
  &AI_NET_OBJ_INSTANCE, &nl_21_layer, AI_STATIC,
  .tensors = &dense_20_fmt_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_20_fmt_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_21_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_21_layer, 21,
  NL_TYPE,
  nl, forward_sm,
  &AI_NET_OBJ_INSTANCE, &nl_21_fmt_layer, AI_STATIC,
  .tensors = &nl_21_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_21_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_21_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_21_fmt_layer, 21,
  NL_TYPE,
  nl, node_convert,
  &AI_NET_OBJ_INSTANCE, &nl_21_fmt_layer, AI_STATIC,
  .tensors = &nl_21_fmt_chain, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 90568, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 67456, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_CIFAR10_IN_NUM, &input_1_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_CIFAR10_OUT_NUM, &nl_21_fmt_output),
  &conversion_0_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool cifar10_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, AI_CIFAR10_ACTIVATIONS_ALIGNMENT));
  AI_ASSERT(activations)
  AI_UNUSED(net_ctx)

  {
    /* Updating activations (byte) offsets */
    conv2d_18_scratch2_array.data = AI_PTR(activations + 34560);
    conv2d_18_scratch2_array.data_start = AI_PTR(activations + 34560);
    conv2d_18_scratch1_array.data = AI_PTR(activations + 34560);
    conv2d_18_scratch1_array.data_start = AI_PTR(activations + 34560);
    conv2d_18_scratch0_array.data = AI_PTR(activations + 32768);
    conv2d_18_scratch0_array.data_start = AI_PTR(activations + 32768);
    conv2d_17_scratch1_array.data = AI_PTR(activations + 0);
    conv2d_17_scratch1_array.data_start = AI_PTR(activations + 0);
    conv2d_17_scratch0_array.data = AI_PTR(activations + 37120);
    conv2d_17_scratch0_array.data_start = AI_PTR(activations + 37120);
    conv2d_16_scratch1_array.data = AI_PTR(activations + 4352);
    conv2d_16_scratch1_array.data_start = AI_PTR(activations + 4352);
    conv2d_16_scratch0_array.data = AI_PTR(activations + 53124);
    conv2d_16_scratch0_array.data_start = AI_PTR(activations + 53124);
    conv2d_15_scratch1_array.data = AI_PTR(activations + 6528);
    conv2d_15_scratch1_array.data_start = AI_PTR(activations + 6528);
    conv2d_15_scratch0_array.data = AI_PTR(activations + 50176);
    conv2d_15_scratch0_array.data_start = AI_PTR(activations + 50176);
    conv2d_14_scratch1_array.data = AI_PTR(activations + 10880);
    conv2d_14_scratch1_array.data_start = AI_PTR(activations + 10880);
    conv2d_14_scratch0_array.data = AI_PTR(activations + 53124);
    conv2d_14_scratch0_array.data_start = AI_PTR(activations + 53124);
    conv2d_13_scratch1_array.data = AI_PTR(activations + 13056);
    conv2d_13_scratch1_array.data_start = AI_PTR(activations + 13056);
    conv2d_13_scratch0_array.data = AI_PTR(activations + 50176);
    conv2d_13_scratch0_array.data_start = AI_PTR(activations + 50176);
    conv2d_12_scratch1_array.data = AI_PTR(activations + 17408);
    conv2d_12_scratch1_array.data_start = AI_PTR(activations + 17408);
    conv2d_12_scratch0_array.data = AI_PTR(activations + 52352);
    conv2d_12_scratch0_array.data_start = AI_PTR(activations + 52352);
    conv2d_11_scratch1_array.data = AI_PTR(activations + 35968);
    conv2d_11_scratch1_array.data_start = AI_PTR(activations + 35968);
    conv2d_11_scratch0_array.data = AI_PTR(activations + 20864);
    conv2d_11_scratch0_array.data_start = AI_PTR(activations + 20864);
    conv2d_10_scratch1_array.data = AI_PTR(activations + 38144);
    conv2d_10_scratch1_array.data_start = AI_PTR(activations + 38144);
    conv2d_10_scratch0_array.data = AI_PTR(activations + 20864);
    conv2d_10_scratch0_array.data_start = AI_PTR(activations + 20864);
    conv2d_9_scratch1_array.data = AI_PTR(activations + 21760);
    conv2d_9_scratch1_array.data_start = AI_PTR(activations + 21760);
    conv2d_9_scratch0_array.data = AI_PTR(activations + 40320);
    conv2d_9_scratch0_array.data_start = AI_PTR(activations + 40320);
    conv2d_8_scratch1_array.data = AI_PTR(activations + 23936);
    conv2d_8_scratch1_array.data_start = AI_PTR(activations + 23936);
    conv2d_8_scratch0_array.data = AI_PTR(activations + 51588);
    conv2d_8_scratch0_array.data_start = AI_PTR(activations + 51588);
    conv2d_7_scratch1_array.data = AI_PTR(activations + 25024);
    conv2d_7_scratch1_array.data_start = AI_PTR(activations + 25024);
    conv2d_7_scratch0_array.data = AI_PTR(activations + 43584);
    conv2d_7_scratch0_array.data_start = AI_PTR(activations + 43584);
    conv2d_6_scratch1_array.data = AI_PTR(activations + 27200);
    conv2d_6_scratch1_array.data_start = AI_PTR(activations + 27200);
    conv2d_6_scratch0_array.data = AI_PTR(activations + 51588);
    conv2d_6_scratch0_array.data_start = AI_PTR(activations + 51588);
    conv2d_5_scratch1_array.data = AI_PTR(activations + 28288);
    conv2d_5_scratch1_array.data_start = AI_PTR(activations + 28288);
    conv2d_5_scratch0_array.data = AI_PTR(activations + 50112);
    conv2d_5_scratch0_array.data_start = AI_PTR(activations + 50112);
    conv2d_4_scratch1_array.data = AI_PTR(activations + 30464);
    conv2d_4_scratch1_array.data_start = AI_PTR(activations + 30464);
    conv2d_4_scratch0_array.data = AI_PTR(activations + 51588);
    conv2d_4_scratch0_array.data_start = AI_PTR(activations + 51588);
    conv2d_3_scratch1_array.data = AI_PTR(activations + 31552);
    conv2d_3_scratch1_array.data_start = AI_PTR(activations + 31552);
    conv2d_3_scratch0_array.data = AI_PTR(activations + 50112);
    conv2d_3_scratch0_array.data_start = AI_PTR(activations + 50112);
    conv2d_2_scratch1_array.data = AI_PTR(activations + 33728);
    conv2d_2_scratch1_array.data_start = AI_PTR(activations + 33728);
    conv2d_2_scratch0_array.data = AI_PTR(activations + 51200);
    conv2d_2_scratch0_array.data_start = AI_PTR(activations + 51200);
    conv2d_1_scratch1_array.data = AI_PTR(activations + 43008);
    conv2d_1_scratch1_array.data_start = AI_PTR(activations + 43008);
    conv2d_1_scratch0_array.data = AI_PTR(activations + 40724);
    conv2d_1_scratch0_array.data_start = AI_PTR(activations + 40724);
    input_1_output_array.data = AI_PTR(NULL);
    input_1_output_array.data_start = AI_PTR(NULL);
    conversion_0_output_array.data = AI_PTR(activations + 37652);
    conversion_0_output_array.data_start = AI_PTR(activations + 37652);
    conv2d_1_output_array.data = AI_PTR(activations + 43008);
    conv2d_1_output_array.data_start = AI_PTR(activations + 43008);
    conv2d_2_output_array.data = AI_PTR(activations + 33728);
    conv2d_2_output_array.data_start = AI_PTR(activations + 33728);
    conv2d_3_output_array.data = AI_PTR(activations + 31552);
    conv2d_3_output_array.data_start = AI_PTR(activations + 31552);
    conv2d_4_output_array.data = AI_PTR(activations + 30464);
    conv2d_4_output_array.data_start = AI_PTR(activations + 30464);
    conv2d_5_output_array.data = AI_PTR(activations + 28288);
    conv2d_5_output_array.data_start = AI_PTR(activations + 28288);
    conv2d_6_output_array.data = AI_PTR(activations + 27200);
    conv2d_6_output_array.data_start = AI_PTR(activations + 27200);
    conv2d_7_output_array.data = AI_PTR(activations + 25024);
    conv2d_7_output_array.data_start = AI_PTR(activations + 25024);
    conv2d_8_output_array.data = AI_PTR(activations + 23936);
    conv2d_8_output_array.data_start = AI_PTR(activations + 23936);
    conv2d_9_output_array.data = AI_PTR(activations + 21760);
    conv2d_9_output_array.data_start = AI_PTR(activations + 21760);
    conv2d_10_output_array.data = AI_PTR(activations + 38144);
    conv2d_10_output_array.data_start = AI_PTR(activations + 38144);
    conv2d_11_output_array.data = AI_PTR(activations + 35968);
    conv2d_11_output_array.data_start = AI_PTR(activations + 35968);
    conv2d_12_output_array.data = AI_PTR(activations + 17408);
    conv2d_12_output_array.data_start = AI_PTR(activations + 17408);
    conv2d_13_output_array.data = AI_PTR(activations + 13056);
    conv2d_13_output_array.data_start = AI_PTR(activations + 13056);
    conv2d_14_output_array.data = AI_PTR(activations + 10880);
    conv2d_14_output_array.data_start = AI_PTR(activations + 10880);
    conv2d_15_output_array.data = AI_PTR(activations + 6528);
    conv2d_15_output_array.data_start = AI_PTR(activations + 6528);
    conv2d_16_output_array.data = AI_PTR(activations + 4352);
    conv2d_16_output_array.data_start = AI_PTR(activations + 4352);
    conv2d_17_output_array.data = AI_PTR(activations + 0);
    conv2d_17_output_array.data_start = AI_PTR(activations + 0);
    conv2d_18_output_array.data = AI_PTR(activations + 67328);
    conv2d_18_output_array.data_start = AI_PTR(activations + 67328);
    dense_20_output_array.data = AI_PTR(activations + 0);
    dense_20_output_array.data_start = AI_PTR(activations + 0);
    dense_20_fmt_output_array.data = AI_PTR(activations + 12);
    dense_20_fmt_output_array.data_start = AI_PTR(activations + 12);
    nl_21_output_array.data = AI_PTR(activations + 52);
    nl_21_output_array.data_start = AI_PTR(activations + 52);
    nl_21_fmt_output_array.data = AI_PTR(NULL);
    nl_21_fmt_output_array.data_start = AI_PTR(NULL);
    
  }
  return true;
}



AI_DECLARE_STATIC
ai_bool cifar10_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT(weights)
  AI_UNUSED(net_ctx)

  {
    /* Updating weights (byte) offsets */
    
    dense_20_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_20_bias_array.data = AI_PTR(weights + 90528);
    dense_20_bias_array.data_start = AI_PTR(weights + 90528);
    dense_20_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_20_weights_array.data = AI_PTR(weights + 89248);
    dense_20_weights_array.data_start = AI_PTR(weights + 89248);
    conv2d_18_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_bias_array.data = AI_PTR(weights + 88736);
    conv2d_18_bias_array.data_start = AI_PTR(weights + 88736);
    conv2d_18_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_weights_array.data = AI_PTR(weights + 72352);
    conv2d_18_weights_array.data_start = AI_PTR(weights + 72352);
    conv2d_17_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_bias_array.data = AI_PTR(weights + 71840);
    conv2d_17_bias_array.data_start = AI_PTR(weights + 71840);
    conv2d_17_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_weights_array.data = AI_PTR(weights + 70688);
    conv2d_17_weights_array.data_start = AI_PTR(weights + 70688);
    conv2d_16_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_bias_array.data = AI_PTR(weights + 70176);
    conv2d_16_bias_array.data_start = AI_PTR(weights + 70176);
    conv2d_16_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_weights_array.data = AI_PTR(weights + 53792);
    conv2d_16_weights_array.data_start = AI_PTR(weights + 53792);
    conv2d_15_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_bias_array.data = AI_PTR(weights + 53280);
    conv2d_15_bias_array.data_start = AI_PTR(weights + 53280);
    conv2d_15_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_weights_array.data = AI_PTR(weights + 52128);
    conv2d_15_weights_array.data_start = AI_PTR(weights + 52128);
    conv2d_14_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_14_bias_array.data = AI_PTR(weights + 51616);
    conv2d_14_bias_array.data_start = AI_PTR(weights + 51616);
    conv2d_14_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_14_weights_array.data = AI_PTR(weights + 35232);
    conv2d_14_weights_array.data_start = AI_PTR(weights + 35232);
    conv2d_13_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_13_bias_array.data = AI_PTR(weights + 34720);
    conv2d_13_bias_array.data_start = AI_PTR(weights + 34720);
    conv2d_13_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_13_weights_array.data = AI_PTR(weights + 33568);
    conv2d_13_weights_array.data_start = AI_PTR(weights + 33568);
    conv2d_12_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_12_bias_array.data = AI_PTR(weights + 33056);
    conv2d_12_bias_array.data_start = AI_PTR(weights + 33056);
    conv2d_12_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_12_weights_array.data = AI_PTR(weights + 24864);
    conv2d_12_weights_array.data_start = AI_PTR(weights + 24864);
    conv2d_11_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_11_bias_array.data = AI_PTR(weights + 24608);
    conv2d_11_bias_array.data_start = AI_PTR(weights + 24608);
    conv2d_11_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_11_weights_array.data = AI_PTR(weights + 24032);
    conv2d_11_weights_array.data_start = AI_PTR(weights + 24032);
    conv2d_10_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_bias_array.data = AI_PTR(weights + 23776);
    conv2d_10_bias_array.data_start = AI_PTR(weights + 23776);
    conv2d_10_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_weights_array.data = AI_PTR(weights + 19680);
    conv2d_10_weights_array.data_start = AI_PTR(weights + 19680);
    conv2d_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_bias_array.data = AI_PTR(weights + 19424);
    conv2d_9_bias_array.data_start = AI_PTR(weights + 19424);
    conv2d_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_weights_array.data = AI_PTR(weights + 18848);
    conv2d_9_weights_array.data_start = AI_PTR(weights + 18848);
    conv2d_8_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_bias_array.data = AI_PTR(weights + 18592);
    conv2d_8_bias_array.data_start = AI_PTR(weights + 18592);
    conv2d_8_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_weights_array.data = AI_PTR(weights + 14496);
    conv2d_8_weights_array.data_start = AI_PTR(weights + 14496);
    conv2d_7_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_bias_array.data = AI_PTR(weights + 14240);
    conv2d_7_bias_array.data_start = AI_PTR(weights + 14240);
    conv2d_7_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_weights_array.data = AI_PTR(weights + 13664);
    conv2d_7_weights_array.data_start = AI_PTR(weights + 13664);
    conv2d_6_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_bias_array.data = AI_PTR(weights + 13408);
    conv2d_6_bias_array.data_start = AI_PTR(weights + 13408);
    conv2d_6_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_weights_array.data = AI_PTR(weights + 9312);
    conv2d_6_weights_array.data_start = AI_PTR(weights + 9312);
    conv2d_5_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_bias_array.data = AI_PTR(weights + 9056);
    conv2d_5_bias_array.data_start = AI_PTR(weights + 9056);
    conv2d_5_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_weights_array.data = AI_PTR(weights + 8480);
    conv2d_5_weights_array.data_start = AI_PTR(weights + 8480);
    conv2d_4_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_bias_array.data = AI_PTR(weights + 8224);
    conv2d_4_bias_array.data_start = AI_PTR(weights + 8224);
    conv2d_4_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_weights_array.data = AI_PTR(weights + 4128);
    conv2d_4_weights_array.data_start = AI_PTR(weights + 4128);
    conv2d_3_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_bias_array.data = AI_PTR(weights + 3872);
    conv2d_3_bias_array.data_start = AI_PTR(weights + 3872);
    conv2d_3_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_weights_array.data = AI_PTR(weights + 3296);
    conv2d_3_weights_array.data_start = AI_PTR(weights + 3296);
    conv2d_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_bias_array.data = AI_PTR(weights + 3040);
    conv2d_2_bias_array.data_start = AI_PTR(weights + 3040);
    conv2d_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_weights_array.data = AI_PTR(weights + 992);
    conv2d_2_weights_array.data_start = AI_PTR(weights + 992);
    conv2d_1_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_bias_array.data = AI_PTR(weights + 864);
    conv2d_1_bias_array.data_start = AI_PTR(weights + 864);
    conv2d_1_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_weights_array.data = AI_PTR(weights + 0);
    conv2d_1_weights_array.data_start = AI_PTR(weights + 0);
  }

  return true;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_cifar10_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_CIFAR10_MODEL_NAME,
      .model_signature   = AI_CIFAR10_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = {AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR,
                            AI_TOOLS_API_VERSION_MICRO, 0x0},

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 22086622,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .activations       = AI_STRUCT_INIT,
      .params            = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if ( !ai_platform_api_get_network_report(network, &r) ) return false;

    *report = r;
    return true;
  }

  return false;
}

AI_API_ENTRY
ai_error ai_cifar10_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_cifar10_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_cifar10_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_cifar10_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= cifar10_configure_weights(net_ctx, &params->params);
  ok &= cifar10_configure_activations(net_ctx, &params->activations);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_cifar10_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_cifar10_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}




#undef AI_CIFAR10_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

