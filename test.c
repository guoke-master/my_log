/***********************************************************************************************************************************************
 * File name:	test.c	
 * Author:	guoke
 * Date:	2022.04.16
 * Description:	对日志工具的测试程序
 * History:	1. 2022.04.16 创建并完成初始版本
 **********************************************************************************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include "my_log.h"

int func_01()
{
	int i = 0;
	LOGD("debug log: %d",i);
	LOGI("info log: %d",i);
	LOGW("warning log: %d",i);
	LOGE("error log: %d",i);
	LOGF("fatal log: %d",i);
}


int main(void)
{
	int i = 0;
	LOGD("debug log: %d",i);
	LOGI("info log: %d",i);
	LOGW("warning log: %d",i);
	LOGE("error log: %d",i);
	LOGF("fatal log: %d",i);

	func_01();

	printf("Hello world!\n");
	return 0;
}

