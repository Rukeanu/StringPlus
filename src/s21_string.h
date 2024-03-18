#ifndef S21_STRING_H
#define S21_STRING_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SI 256
#define s21_NULL (void*)0
#define POS_INF 1.0 / 0.0
#define NEG_INF -1.0 / 0.0
typedef long unsigned s21_size_t;
#define NUM_SPECIFIERS 14
#define SPECIFIERS "cdfsugGeExXop%%"
#define LENGTH "hlL"
#define NUM_FLAGS 5
#define FLAGS "-+ #0"
#define DIGITS "0123456789abcdef"
#define BUF_SIZE 32

struct s_sprintf;

typedef struct s_specifiers {
  char specifier;
  void (*process_spec)(char** str, va_list arglist,
                       struct s_sprintf* sprintf_args, int* count);
  char is;
} t_specifiers;

typedef struct s_flags {
  char flag;
  bool is;
} t_flags;

typedef struct s_sprintf {
  t_specifiers specifier[NUM_SPECIFIERS];
  t_flags flags[NUM_FLAGS];
  int width;
  int precision;
  char length;
} t_sprintf;

// PART 1
void* s21_memchr(const void* str, int c, s21_size_t n);
int s21_memcmp(const void* str1, const void* str2, s21_size_t n);
void* s21_memcpy(void* dest, const void* src, s21_size_t n);
void* s21_memset(void* str, int c, s21_size_t n);
char* s21_strncat(char* dest, const char* src, s21_size_t n);
char* s21_strchr(const char* str, int c);
int s21_strncmp(const char* str1, const char* str2, s21_size_t n);
char* s21_strncpy(char* dest, const char* src, s21_size_t n);
s21_size_t s21_strcspn(const char* str1, const char* str2);
char* s21_strerror(int errnum);
s21_size_t s21_strlen(const char* str);
char* s21_strpbrk(const char* str1, const char* str2);
char* s21_strrchr(const char* str, int c);
char* s21_strstr(const char* haystack, const char* needle);
char* s21_strtok(char* str, const char* delim);

// PART 2-3
int s21_sprintf(char* str, const char* format, ...);

// PART 4
int s21_sscanf(const char* str, const char* format, ...);
int value_assignment(int result, const char* format, const char* input,
                     va_list v_args);
void valid(int result, char* format, const char* input, va_list v_args);
void width_value_assignment(int result, const char* format, int width,
                            const char* input, va_list v_args);
void fake_taxi(const char* format, va_list v_args);
void buffer(int result, const char* str, const char* format, va_list v_args);

// PART 5
void* s21_to_lower(const char* str);
void* s21_to_upper(const char* str);
void* s21_trim(const char* src, const char* trim_chars);
void* s21_insert(const char* src, const char* str, s21_size_t start_index);

int parse_format(char** str, const char* format, va_list arglist);
void init_flags(t_sprintf* sprintf_args);
void process_percent(char** str, const char* format, va_list arglist,
                     t_sprintf* sprintf_args, int* count, int* i);

void parse_flags(const char* format, va_list arglist, t_sprintf* sprintf_args,
                 int* i);
void parse_width(const char* format, va_list arglist, t_sprintf* sprintf_args,
                 int* i);
void parse_precision(const char* format, va_list arglist,
                     t_sprintf* sprintf_args, int* i);
void parse_length(const char* format, va_list arglist, t_sprintf* sprintf_args,
                  int* i);
void parse_specifiers(const char* format, va_list arglist,
                      t_sprintf* sprintf_args, int* i);

void fill_sign(char** str, int sign, t_sprintf* sprintf_args, int* count);
void fill_space(char** str, int num, char c, int* count);
void fill_str(char** str, char* str_value, int str_value_len, int* count);
void fill_prefix(char** str, t_sprintf* sprintf_args, int radix, int* count);

void process_int(char** str, va_list arglist, t_sprintf* sprintf_args,
                 int* count);
void process_char(char** str, va_list arglist, t_sprintf* sprintf_args,
                  int* count);
void process_float(char** str, va_list arglist, t_sprintf* sprintf_args,
                   int* count);
void process_string(char** str, va_list arglist, t_sprintf* sprintf_args,
                    int* count);
void process_uint(char** str, va_list arglist, t_sprintf* sprintf_args,
                  int* count);
bool is_in_str(const char c, const char* str);
bool is_digit(const char c);
size_t custom_strlen(const char* str);
void* extended_realloc(void* ptr, s21_size_t size);
void fatal(int errnum);
int extract_num_from_format(const char* format, int* i);
char* s21_itoa(long long value, int radix);
bool get_flag_value(t_flags* flags, char flag);
char* s21_ftoa(long double num, int precision, bool hash_flag);
char* s21_etoa(long double num, int precision, char char_e, bool hash_flag);
char* s21_gtoa(long double num, int precision, char char_e, bool hash_flag);
char* s21_strdup(const char* s1);
char* s21_strjoin(char const* s1, char const* s2);
int s21_strcmp(const char* str1, const char* str2);
char* s21_strcpy(char* dest, const char* source);
void free_line(char** line);
char* strjoin_with_free(char** s1, char** s2);
bool get_spec_value(t_specifiers* specifiers, char specifier);

#endif