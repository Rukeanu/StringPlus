#include "s21_string.h"

void process_string(char** str, va_list arglist, t_sprintf* sprintf_args,
                    int* count) {
  char* value = va_arg(arglist, char*);
  sprintf_args->precision =
      sprintf_args->precision < 0 ? 2147483647 : sprintf_args->precision;
  int str_value_len = (int)s21_strlen(value) < sprintf_args->precision
                          ? (int)s21_strlen(value)
                          : sprintf_args->precision;
  sprintf_args->width -= str_value_len;
  if (get_flag_value(sprintf_args->flags, '-')) {
    fill_str(str, value, str_value_len, count);
    fill_space(str, sprintf_args->width, ' ', count);
  } else {
    if (get_flag_value(sprintf_args->flags, '0'))
      fill_space(str, sprintf_args->width, '0', count);
    else
      fill_space(str, sprintf_args->width, ' ', count);
    fill_str(str, value, str_value_len, count);
  }
}
