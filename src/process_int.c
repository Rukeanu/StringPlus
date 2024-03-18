#include "s21_string.h"

void process_int(char** str, va_list arglist, t_sprintf* sprintf_args,
                 int* count) {
  long long value = 0;

  if (sprintf_args->length == 'h')
    value = (short)va_arg(arglist, int);
  else if (sprintf_args->length == 'l')
    value = va_arg(arglist, long);
  else if (sprintf_args->length == 'L')
    value = va_arg(arglist, long long);
  else
    value = va_arg(arglist, int);
  int sign = value < 0 ? -1 : 1;
  char* str_value = s21_itoa(value * sign, 10);
  s21_size_t str_value_len = s21_strlen(str_value);
  sprintf_args->width -= str_value_len;
  int orig_precision = sprintf_args->precision;
  sprintf_args->precision -= str_value_len;
  if (get_flag_value(sprintf_args->flags, '-')) {
    fill_sign(str, sign, sprintf_args, count);
    fill_space(str, sprintf_args->precision, '0', count);
    fill_str(str, str_value, str_value_len, count);
    fill_space(str, sprintf_args->width, ' ', count);
  } else {
    if (orig_precision <= 0) {
      if (get_flag_value(sprintf_args->flags, '0')) {
        fill_sign(str, sign, sprintf_args, count);
        fill_space(str, sprintf_args->width, '0', count);
      } else {
        if (sign < 0 || get_flag_value(sprintf_args->flags, '+'))
          sprintf_args->width--;
        fill_space(str, sprintf_args->width, ' ', count);
        fill_sign(str, sign, sprintf_args, count);
      }
      fill_str(str, str_value, str_value_len, count);
    } else {
      if (sign < 0 || get_flag_value(sprintf_args->flags, '+'))
        sprintf_args->width--;
      sprintf_args->width -= sprintf_args->precision;
      fill_space(str, sprintf_args->width, ' ', count);
      fill_sign(str, sign, sprintf_args, count);
      fill_space(str, sprintf_args->precision, '0', count);
      fill_str(str, str_value, str_value_len, count);
    }
  }
  free(str_value);
}
