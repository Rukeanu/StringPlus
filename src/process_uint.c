#include "s21_string.h"

int get_radix(t_specifiers* specifiers) {
  int radix = 10;
  if (get_spec_value(specifiers, 'o'))
    radix = 8;
  else if (get_spec_value(specifiers, 'x') || get_spec_value(specifiers, 'X') ||
           get_spec_value(specifiers, 'p'))
    radix = 16;
  return radix;
}

void process_uint(char** str, va_list arglist, t_sprintf* sprintf_args,
                  int* count) {
  char* tmp = s21_NULL;
  unsigned long long value = 0;
  if (sprintf_args->length == 'h')
    value = (short)va_arg(arglist, unsigned int);
  else if (sprintf_args->length == 'l')
    value = va_arg(arglist, unsigned long);
  else if (sprintf_args->length == 'L' ||
           get_spec_value(sprintf_args->specifier, 'p'))
    value = va_arg(arglist, unsigned long long);
  else
    value = va_arg(arglist, int);
  int radix = get_radix(sprintf_args->specifier);
  if (get_spec_value(sprintf_args->specifier, 'p')) {
    for (uint8_t i = 0; i < NUM_FLAGS; i++) {
      if (sprintf_args->flags[i].flag == '#') sprintf_args->flags[i].is = true;
    }
  }
  char* str_value = s21_itoa(value, radix);
  if (get_spec_value(sprintf_args->specifier, 'X')) {
    tmp = str_value;
    str_value = s21_to_upper(str_value);
    free_line(&tmp);
  }
  s21_size_t str_value_len = s21_strlen(str_value);
  sprintf_args->width -= str_value_len;
  int orig_precision = sprintf_args->precision;
  sprintf_args->precision -= str_value_len;
  if (get_flag_value(sprintf_args->flags, '-')) {
    fill_prefix(str, sprintf_args, radix, count);
    fill_space(str, sprintf_args->precision, '0', count);
    fill_str(str, str_value, str_value_len, count);
    fill_space(str, sprintf_args->width, ' ', count);
  } else {
    if (orig_precision <= 0) {
      if (get_flag_value(sprintf_args->flags, '0')) {
        fill_prefix(str, sprintf_args, radix, count);
        fill_space(str, sprintf_args->width, '0', count);
      } else {
        fill_space(str, sprintf_args->width, ' ', count);
        fill_prefix(str, sprintf_args, radix, count);
      }
      fill_str(str, str_value, str_value_len, count);
    } else {
      sprintf_args->width -= sprintf_args->precision;
      fill_space(str, sprintf_args->width, ' ', count);
      fill_prefix(str, sprintf_args, radix, count);
      fill_space(str, sprintf_args->precision, '0', count);
      fill_str(str, str_value, str_value_len, count);
    }
  }
  free(str_value);
}
