/***********************************************************************************************************************************************
 * File name:	my_log.h
 * Author:	guoke
 * Date:	2022.04.16
 * Description:	自定义日志系统的头文件，声明了Trace函数和5个LOG宏
 * History:	1. 2022.04.16 创建并完成初始版本
 **********************************************************************************************************************************************/
#ifndef __MY_LOG__
#define __MY_LOG__

#ifdef __cplusplus
extern "C"{
#endif


#define LOG_BUFFER_SIZE (1024 * 1024)


void Trace(int level, const char* file, const int line, const char* function, const char* fmt, ... );


#define LOGD(...) Trace(0, __FILE__, __LINE__, __func__, __VA_ARGS__)
#define LOGI(...) Trace(1, __FILE__, __LINE__, __func__, __VA_ARGS__)
#define LOGW(...) Trace(2, __FILE__, __LINE__, __func__, __VA_ARGS__)
#define LOGE(...) Trace(3, __FILE__, __LINE__, __func__, __VA_ARGS__)
#define LOGF(...) Trace(4, __FILE__, __LINE__, __func__, __VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif
