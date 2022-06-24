/***********************************************************************************************************************************************
 * File name:	test.c	
 * Author:	guoke
 * Date:	2022.04.16
 * Description:	对日志工具的测试程序
 * History:	1. 2022.04.16 创建并完成初始版本
 *			2. 2022.06.21 由于更改项目目录结构，更改了my_log.h的include语句
 **********************************************************************************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include "../include/my_log.h"

int func_01()
{
	int i = 0;
	LOGD(g_log_file_path, "debug log: %d",i);
	LOGI(g_log_file_path, "info log: %d",i);
	LOGW(g_log_file_path, "warning log: %d",i);
	LOGE(g_log_file_path, "error log: %d",i);
	LOGF(g_log_file_path, "fatal log: %d",i);
	return 0;
}


int main(void)
{
	int i = 0;

	g_log_file_path = "./log/log.txt";
	LOGD(g_log_file_path, "debug log: %d",i);
	LOGI(g_log_file_path, "info log: %d",i);
	LOGW(g_log_file_path, "warning log: %d",i);
	LOGE(g_log_file_path, "error log: %d",i);
	LOGF(g_log_file_path, "fatal log: %d",i);

	func_01();

	printf("Hello world!\n");
	return 0;
}

