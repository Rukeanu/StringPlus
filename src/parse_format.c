#include "s21_string.h"

int parse_format(char **str, const char *format, va_list arglist) {
  int count = 0;
  int format_len = s21_strlen(format);
  int i = 0;
  while (i < format_len) {
    t_sprintf sprintf_args = {0};
    init_flags(&sprintf_args);
    if (format[i] == '%') {
      process_percent(str, format, arglist, &sprintf_args, &count, &(i));
    }
    if (format[i]) (*str)[count++] = format[i];
    i++;
  }
  return count;
}
