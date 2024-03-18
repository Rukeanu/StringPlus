#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  int count = 0;
  va_list arglist;
  va_start(arglist, format);
  count = parse_format(&str, format, arglist);
  va_end(arglist);
  return count;
}
