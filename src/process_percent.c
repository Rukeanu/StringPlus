#include "s21_string.h"

void process_percent(char** str, const char* format, va_list arglist,
                     t_sprintf* sprintf_args, int* count, int* i) {
  void (*sprintf_parse_funcs[])(const char* format, va_list arglist,
                                t_sprintf* sprintf_args, int* k) = {
      parse_flags,  parse_width,      parse_precision,
      parse_length, parse_specifiers, s21_NULL};
  (*i)++;
  int tmp_i = *i;
  for (uint8_t j = 0; sprintf_parse_funcs[j] != s21_NULL; j++)
    sprintf_parse_funcs[j](format, arglist, sprintf_args, i);

  if (*i - tmp_i == 0) {
    (*i)++;
    return;
  }
  for (uint8_t j = 0; j < NUM_SPECIFIERS; j++)
    if (sprintf_args->specifier[j].is &&
        sprintf_args->specifier[j].process_spec)
      sprintf_args->specifier[j].process_spec(str, arglist, sprintf_args,
                                              count);
}
