#include "s21_string.h"

void fill_sign(char** str, int sign, t_sprintf* sprintf_args, int* count) {
  if (sign < 0) {
    (*str)[(*count)++] = '-';
    sprintf_args->width--;
  } else if (get_flag_value(sprintf_args->flags, '+')) {
    (*str)[(*count)++] = '+';
    sprintf_args->width--;
  } else if (get_flag_value(sprintf_args->flags, ' ')) {
    (*str)[(*count)++] = ' ';
    sprintf_args->width--;
  }
}

void fill_space(char** str, int num, char c, int* count) {
  for (; num > 0; num--) (*str)[(*count)++] = c;
}

void fill_str(char** str, char* str_value, int str_value_len, int* count) {
  for (int j = 0; j < str_value_len; j++) (*str)[(*count)++] = str_value[j];
}

void fill_prefix(char** str, t_sprintf* sprintf_args, int radix, int* count) {
  if (get_flag_value(sprintf_args->flags, '#') && (radix == 8 || radix == 16)) {
    fill_str(str, "0", 1, count);
    sprintf_args->width--;
    if (get_spec_value(sprintf_args->specifier, 'x') ||
        get_spec_value(sprintf_args->specifier, 'p')) {
      fill_str(str, "x", 1, count);
      sprintf_args->width--;
    } else if (get_spec_value(sprintf_args->specifier, 'X')) {
      fill_str(str, "X", 1, count);
      sprintf_args->width--;
    }
  }
}
