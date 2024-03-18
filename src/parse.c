#include "s21_string.h"

void parse_flags(const char* format, va_list arglist, t_sprintf* sprintf_args,
                 int* i) {
  (void)arglist;
  while (is_in_str(format[*i], FLAGS)) {
    for (uint8_t j = 0; j < NUM_FLAGS; j++)
      if (sprintf_args->flags[j].flag == format[*i])
        sprintf_args->flags[j].is = true;
    (*i)++;
  }
}

void parse_width(const char* format, va_list arglist, t_sprintf* sprintf_args,
                 int* i) {
  if (format[*i] == '*') {
    sprintf_args->width = va_arg(arglist, int);
    (*i)++;
  } else
    sprintf_args->width = extract_num_from_format(format, i);
}

void parse_precision(const char* format, va_list arglist,
                     t_sprintf* sprintf_args, int* i) {
  sprintf_args->precision = -1;
  if (format[*i] == '.') {
    (*i)++;
    if (format[*i] == '*') {
      sprintf_args->precision = va_arg(arglist, int);
      (*i)++;
    } else
      sprintf_args->precision = extract_num_from_format(format, i);
  }
}

void parse_length(const char* format, va_list arglist, t_sprintf* sprintf_args,
                  int* i) {
  (void)arglist;
  if (is_in_str(format[*i], LENGTH)) sprintf_args->length = format[(*i)++];
}

void parse_specifiers(const char* format, va_list arglist,
                      t_sprintf* sprintf_args, int* i) {
  (void)arglist;
  if (is_in_str(format[*i], SPECIFIERS)) {
    for (uint8_t j = 0; j < NUM_SPECIFIERS; j++)
      if (sprintf_args->specifier[j].specifier == format[*i])
        sprintf_args->specifier[j].is = true;
    (*i)++;
  }
}
