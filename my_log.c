/***********************************************************************************************************************************************
 * File name:	my_log.c
 * Author:	guoke
 * Date:	2022.04.16
 * Description:	自定义日志系统的源文件，实现了Trace函数和日志级别的定义
 * History:	1. 2022.04.16 创建并完成初始版本
 **********************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "my_log.h"

/* 日志的级别 */
const char* g_level[] = {
	"DEBUG", "INFO", "WARNING", "ERROR", "FATAL"
};

void Trace(int level, const char* file, const int line, const char* function, const char* fmt, ... )
{

	va_list ap;			// 可变参数
	int ret = 0;		// 函数返回值，用于判断调用是否成功


	/* 
	 * TODO:	1. 每次调用这个函数都需要分配和释放空间，对效率有所影响。但是对这个缓冲空间是线程安全的
	 *			2. 优化调用效率，可以固定一个空间，不必每次都分配与释放，但是需要解决线程安全问题
	 */
	/* 缓存日志信息的缓冲区 */
	char* buffer = (char*)malloc(LOG_BUFFER_SIZE);
	if (buffer == NULL)
	{
		printf("Failed to allocte log buffer: buffer == NULL\n");
		return;
	}
	memset(buffer, 0, LOG_BUFFER_SIZE);

	/* 输入检查 */
	if (level < 0)
	{
		level = 0;
		printf("warning: level < 0\n");
	}
	if (level > 4)
	{
		level = 4;
		printf("warning: level > 4\n");
	}

	/* 可变参数 */
	va_start(ap, fmt);


	/* 
	 * TODO:	添加VC支持。注意GCC与VC在实现上的差异（返回值与第二个参数
	 */
	/* 将文件名，行数，函数名等信息写入到缓冲区之中 */
	snprintf(buffer, LOG_BUFFER_SIZE, "%s(%d) : <%s>.[%s]", file, line, g_level[level], function);

	/*
	 * TODO:	添加VC支持。注意GCC与VC在是实现上的差异
	 */
	/* 将用户输入的信息加到缓冲区之后 */
	vsnprintf(buffer + strlen(buffer), LOG_BUFFER_SIZE - strlen(buffer), fmt, ap);

	// 输出
	printf("%s\n",buffer);


	// 释放可变缓冲区空间
	va_end(ap);

	// 释放缓冲区，防止野指针
	if (buffer != NULL)
	{
		free(buffer);
		buffer = NULL;
	}
}


