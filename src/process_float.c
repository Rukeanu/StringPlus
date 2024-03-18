#include "s21_string.h"

void process_float(char** str, va_list arglist, t_sprintf* sprintf_args,
                   int* count) {
  long double value = 0;
  char* tmp = s21_NULL;
  if (sprintf_args->length == 'L')
    value = va_arg(arglist, long double);
  else
    value = va_arg(arglist, double);
  int sign = value < 0 ? -1 : 1;
  char* str_value = s21_NULL;
  sprintf_args->precision =
      sprintf_args->precision < 0 ? 6 : sprintf_args->precision;
  if (isnan(value))
    str_value = s21_strdup("nan");
  else if (value == POS_INF || value == NEG_INF)
    str_value = s21_strdup("inf");
  else {
    if (get_spec_value(sprintf_args->specifier, 'f'))
      str_value = s21_ftoa(value * sign, sprintf_args->precision,
                           get_flag_value(sprintf_args->flags, '#'));
    else if (get_spec_value(sprintf_args->specifier, 'e'))
      str_value = s21_etoa(value * sign, sprintf_args->precision, 'e',
                           get_flag_value(sprintf_args->flags, '#'));
    else if (get_spec_value(sprintf_args->specifier, 'E')) {
      tmp = s21_etoa(value * sign, sprintf_args->precision, 'E',
                     get_flag_value(sprintf_args->flags, '#'));
      str_value = s21_to_upper(tmp);
      free_line(&tmp);
    } else if (get_spec_value(sprintf_args->specifier, 'g'))
      str_value = s21_gtoa(value * sign, sprintf_args->precision, 'e',
                           get_flag_value(sprintf_args->flags, '#'));
    else if (get_spec_value(sprintf_args->specifier, 'G')) {
      tmp = s21_gtoa(value * sign, sprintf_args->precision, 'E',
                     get_flag_value(sprintf_args->flags, '#'));
      str_value = s21_to_upper(tmp);
      free_line(&tmp);
    }
  }
  s21_size_t str_value_len = s21_strlen(str_value);
  sprintf_args->width -= str_value_len;
  if (get_flag_value(sprintf_args->flags, '-')) {
    fill_sign(str, sign, sprintf_args, count);
    fill_str(str, str_value, str_value_len, count);
    fill_space(str, sprintf_args->width, ' ', count);
  } else {
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
  }
  free(str_value);
}
