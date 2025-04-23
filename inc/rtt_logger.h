#ifndef RTT_LOGGER_H_
#define RTT_LOGGER_H_

typedef enum {
  LOG_LEVEL_DEBUG,
  LOG_LEVEL_INFO,
  LOG_LEVEL_WARN,
  LOG_LEVEL_ERROR
} LogLevel;

#define INFO_LOG(format, ...)                                                  \
  rtt_log(LOG_LEVEL_INFO, __FILE_NAME__, __func__, format, ##__VA_ARGS__)
#define DEBUG_LOG(format, ...)                                                 \
  rtt_log(LOG_LEVEL_DEBUG, __FILE_NAME__, __func__, format, ##__VA_ARGS__)
#define WARN_LOG(format, ...)                                                  \
  rtt_log(LOG_LEVEL_WARN, __FILE_NAME__, __func__, format, ##__VA_ARGS__)
#define ERROR_LOG(format, ...)                                                 \
  rtt_log(LOG_LEVEL_ERROR, __FILE_NAME__, __func__, format, ##__VA_ARGS__)

void rtt_log(LogLevel level, const char *log_file, const char *log_func,
             const char *fmt, ...);

#endif /* RTT_LOGGER_H_ */
