#include "rtt_logger.h"
#include "SEGGER_RTT.h"
#include <stdint.h>
#include <stdio.h>

#define RTT_COLOR_RESET "\033[0m"
#define RTT_COLOR_RED "\033[31m"
#define RTT_COLOR_YELLOW "\033[33m"
#define RTT_COLOR_GREEN "\033[32m"
#define RTT_COLOR_BLUE "\033[34m"

extern uint32_t HAL_GetTick(void);

uint32_t get_millis(void) { return HAL_GetTick(); }

void rtt_log(LogLevel level, const char *log_file, const char *log_func,
             const char *fmt, ...) {
  const char *color;
  const char *level_str;

  switch (level) {
  case LOG_LEVEL_DEBUG:
    color = RTT_COLOR_BLUE;
    level_str = "DEBUG";
    break;
  case LOG_LEVEL_INFO:
    color = RTT_COLOR_GREEN;
    level_str = "INFO";
    break;
  case LOG_LEVEL_WARN:
    color = RTT_COLOR_YELLOW;
    level_str = "WARN";
    break;
  case LOG_LEVEL_ERROR:
    color = RTT_COLOR_RED;
    level_str = "ERROR";
    break;
  default:
    color = RTT_COLOR_RESET;
    level_str = "UNKNOWN";
    break;
  }

  uint32_t millis = get_millis();

  char message[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(message, sizeof(message), fmt, args);
  va_end(args);

  // Wyświetlenie wiadomości z kolorami i czasem
  SEGGER_RTT_printf(0, "%lu.%03lu %s[%s]%s %s::%s::%s\n", millis / 1000,
                    millis % 1000, color, level_str, RTT_COLOR_RESET, log_file,
                    log_func, message);
}
