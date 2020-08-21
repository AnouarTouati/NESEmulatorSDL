#pragma once

#ifdef _DEBUG
		#define LOG_TRACE(...)     Logger->trace(__VA_ARGS__)
		#define LOG_INFO(...)      Logger->info(__VA_ARGS__)
		#define LOG_WARN(...)      Logger->warn(__VA_ARGS__)
		#define LOG_ERROR(...)     Logger->error(__VA_ARGS__)
		#define LOG_FATAL(...)     Logger->fatal(__VA_ARGS__)
#else 
		#define LOG_TRACE(...)    
		#define LOG_INFO(...)     
		#define LOG_WARN(...)     
		#define LOG_ERROR(...)    
		#define LOG_FATAL(...) 
#endif

