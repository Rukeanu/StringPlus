#include "s21_string.h"

void process_char(char** str, va_list arglist, t_sprintf* sprintf_args,
                  int* count) {
  char value = 0;
  if (get_spec_value(sprintf_args->specifier, '%'))
    value = '%';
  else {
    if (sprintf_args->length == 'l')
      value = va_arg(arglist, wchar_t);
    else
      value = va_arg(arglist, int);
  }
  sprintf_args->width--;
  sprintf_args->precision = 0;

  if (get_flag_value(sprintf_args->flags, '-')) {
    (*str)[(*count)++] = value;
    fill_space(str, sprintf_args->width, ' ', count);
  } else {
    char space = get_flag_value(sprintf_args->flags, '0') ? '0' : ' ';
    fill_space(str, sprintf_args->width, space, count);
    (*str)[(*count)++] = value;
  }
}
