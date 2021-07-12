#ifndef __RT_AI_CIFAR10_MODEL_H
#define __RT_AI_CIFAR10_MODEL_H

/* model info ... */

// model name
#define RT_AI_CIFAR10_MODEL_NAME			"cifar10"

#define RT_AI_CIFAR10_WORK_BUFFER_BYTES		(67456)

#define AI_CIFAR10_DATA_WEIGHTS_SIZE		(90568)

#define RT_AI_CIFAR10_BUFFER_ALIGNMENT		(4)

#define RT_AI_CIFAR10_IN_NUM				(1)

#define RT_AI_CIFAR10_IN_SIZE_BYTES	{	\
	((32 * 32 * 3) * 1),	\
}
#define RT_AI_CIFAR10_IN_1_SIZE			(32 * 32 * 3)
#define RT_AI_CIFAR10_IN_1_SIZE_BYTES		((32 * 32 * 3) * 1)
#define RT_AI_CIFAR10_IN_TOTAL_SIZE_BYTES		((32 * 32 * 3) * 1)



#define RT_AI_CIFAR10_OUT_NUM				(1)

#define RT_AI_CIFAR10_OUT_SIZE_BYTES	{	\
	((1 * 1 * 10) * 1),	\
}
#define RT_AI_CIFAR10_OUT_1_SIZE			(1 * 1 * 10)
#define RT_AI_CIFAR10_OUT_1_SIZE_BYTES		((1 * 1 * 10) * 1)
#define RT_AI_CIFAR10_OUT_TOTAL_SIZE_BYTES		((1 * 1 * 10) * 1)




#define RT_AI_CIFAR10_TOTAL_BUFFER_SIZE		//unused

#endif	//end
