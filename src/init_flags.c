#include "s21_string.h"

void init_flags(t_sprintf* sprintf_args) {
  for (uint8_t i = 0; i < NUM_FLAGS; i++) {
    sprintf_args->flags[i].flag = FLAGS[i];
    sprintf_args->flags[i].is = false;
  }
  void (*process_specs[])(char** str, va_list arglist, t_sprintf* sprintf_args,
                          int* count) = {
      process_char,  process_int,   process_float, process_string, process_uint,
      process_float, process_float, process_float, process_float,  process_uint,
      process_uint,  process_uint,  process_uint,  process_char,   s21_NULL,
  };
  for (uint8_t i = 0; i < NUM_SPECIFIERS; i++) {
    sprintf_args->specifier[i].specifier = SPECIFIERS[i];
    sprintf_args->specifier[i].process_spec = process_specs[i];
    sprintf_args->specifier[i].is = false;
  }
}