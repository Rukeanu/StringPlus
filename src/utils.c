#include "s21_string.h"

bool is_in_str(const char c, const char* str) {
  uint8_t len = s21_strlen(str);
  for (uint8_t i = 0; i < len; i++)
    if (c == str[i]) return true;
  return false;
}

bool is_digit(const char c) { return (c >= '0' && c <= '9') ? true : false; }

size_t custom_strlen(const char* str) {
  size_t length = 0;
  while (str[length] != '\0') {
    length++;
  }
  return length;
}

void* extended_realloc(void* ptr, s21_size_t size) {
  void* result = ptr ? realloc(ptr, size) : malloc(size);
  if (size && !result) fatal(0);
  return result;
}

void fatal(int errnum) {
  write(2, s21_strerror(errnum), s21_strlen(s21_strerror(errnum)));
  exit(errnum);
}

int extract_num_from_format(const char* format, int* i) {
  int num = 0;

  while (is_digit(format[*i])) {
    num = num * 10 + format[*i] - '0';
    (*i)++;
  }
  return num;
}

int s21_strcmp(const char* str1, const char* str2) {
  const unsigned char* c1 = (const unsigned char*)str1;
  const unsigned char* c2 = (const unsigned char*)str2;

  while (*c1 && *c1 == *c2) ++c1, ++c2;

  return *(const unsigned char*)c1 - *(const unsigned char*)c2;
}

char* s21_strcpy(char* dest, const char* source) {
  char* dest_ptr = dest;

  while ((*dest_ptr++ = *source++) != '\0')
    ;

  return dest;
}

s21_size_t s21_strlcpy(char* restrict dst, const char* restrict src,
                       s21_size_t dstsize) {
  s21_size_t i;
  s21_size_t len_src;

  if (!dst || !src) return (0);
  len_src = 0;
  while (src[len_src] != '\0') len_src++;
  i = 0;
  if (dstsize > 0) {
    while (i < (dstsize - 1) && src[i] != '\0') {
      dst[i] = src[i];
      i++;
    }
    dst[i] = '\0';
  }
  return (len_src);
}

char* s21_strdup(const char* s1) {
  s21_size_t len_s1;
  char* new_str;

  len_s1 = s21_strlen(s1);
  new_str = malloc(sizeof(char) * (len_s1 + 1));
  if (new_str == s21_NULL) return (s21_NULL);
  s21_strlcpy(new_str, s1, len_s1 + 1);
  return (new_str);
}

void fill_new_str(char* new_str, char const* s1, char const* s2,
                  s21_size_t len_new_str) {
  s21_size_t i;
  s21_size_t len_s1;

  len_s1 = s21_strlen(s1);
  i = 0;
  while (i < len_s1) {
    new_str[i] = s1[i];
    i++;
  }
  while (i < len_new_str) {
    new_str[i] = s2[i - len_s1];
    i++;
  }
  new_str[i] = '\0';
}

char* s21_strjoin(char const* s1, char const* s2) {
  char* new_str;
  s21_size_t len_s1;
  s21_size_t len_s2;
  s21_size_t len_new_str;

  if (!s1 || !s2) return (s21_NULL);
  len_s1 = s21_strlen(s1);
  len_s2 = s21_strlen(s2);
  len_new_str = len_s1 + len_s2;
  new_str = malloc(sizeof(char) * (len_new_str + 1));
  if (!new_str) return (s21_NULL);
  fill_new_str(new_str, s1, s2, len_new_str);
  return (new_str);
}

bool get_flag_value(t_flags* flags, char flag) {
  for (uint8_t i = 0; i < NUM_FLAGS; i++) {
    if (flags[i].flag == flag) return flags[i].is;
  }
  return false;
}

bool get_spec_value(t_specifiers* specifiers, char specifier) {
  for (uint8_t i = 0; i < NUM_SPECIFIERS; i++) {
    if (specifiers[i].specifier == specifier) return specifiers[i].is;
  }
  return false;
}

void free_line(char** line) {
  if (line && *line) {
    free(*line);
    *line = s21_NULL;
  }
}

char* strjoin_with_free(char** s1, char** s2) {
  char* result = s21_strjoin(*s1, *s2);
  free_line(s1);
  free_line(s2);
  return result;
}

char* char_to_str(char c) {
  char* res = extended_realloc(s21_NULL, 2);
  res[0] = c;
  res[1] = '\0';
  return res;
}

char* s21_itoa(long long value, int radix) {
  char* result = s21_NULL;
  if (value == 0)
    result = s21_strdup("0");
  else {
    for (; value; value /= radix) {
      char* str_digit = char_to_str(DIGITS[value % radix]);
      result = !result ? str_digit : strjoin_with_free(&str_digit, &result);
    }
  }
  return result;
}

char* s21_ftoa(long double num, int precision, bool hash_flag) {
  long double integer_part;
  long double fractional_part;
  int sign = num < 0 ? -1 : 1;
  char* result = s21_NULL;

  fractional_part = modfl(num, &integer_part) * sign;
  integer_part +=
      roundl(fractional_part * powl(10, precision)) / powl(10, precision);
  result = s21_itoa((long long)integer_part, 10);
  if (precision > 0 || hash_flag) {
    fractional_part =
        precision > 0 ? roundl(fractional_part * powl(10, precision)) : 0;
    char* dot_str = s21_strdup(".");
    char* frac_str = s21_itoa((int)fractional_part, 10);
    int frac_str_len = (int)s21_strlen(frac_str);
    for (int i = 0; i + frac_str_len < precision; i++) {
      char* zero_str = char_to_str('0');
      frac_str = strjoin_with_free(&zero_str, &frac_str);
    }
    result = strjoin_with_free(&result, &dot_str);
    result = strjoin_with_free(&result, &frac_str);
  }
  return result;
}

char* s21_etoa(long double num, int precision, char char_e, bool hash_flag) {
  long double expo = floorl(log10l(num));
  long double mant = num / powl(10, (int)expo);
  expo = (expo == POS_INF || expo == NEG_INF) ? 0 : expo;
  mant = isnan(mant) ? 0 : mant;
  char* result = s21_ftoa(mant, precision, hash_flag);
  char* e_str = char_to_str(char_e);
  result = strjoin_with_free(&result, &e_str);
  int exp_sign = expo < 0 ? -1 : 1;
  char exp_sign_char = expo < 0 ? '-' : '+';
  char* exp_sign_str = char_to_str(exp_sign_char);
  result = strjoin_with_free(&result, &exp_sign_str);
  char* exp_str = s21_itoa((long long)expo * exp_sign, 10);
  if (s21_strlen(exp_str) == 1) {
    char* zero_str = char_to_str('0');
    exp_str = strjoin_with_free(&zero_str, &exp_str);
  }
  result = strjoin_with_free(&result, &exp_str);
  return result;
}

char* reverse_str(char* str) {
  s21_size_t len_str = s21_strlen(str);
  char* result = calloc(len_str, sizeof(char*));
  for (int i = len_str - 1; i >= 0; i--) result[len_str - i - 1] = str[i];
  return result;
}

char* s21_gtoa(long double num, int precision, char char_e, bool hash_flag) {
  char* result = s21_NULL;
  char* tmp = s21_NULL;
  int len_result = 0;
  int i, j;

  long double expo = floorl(log10l(num));
  expo = (expo == POS_INF || expo == NEG_INF) ? 0 : expo;
  if (precision < expo || expo < -4) {
    precision = precision - 1 < 0 ? 0 : precision - 1;
    result = s21_etoa(num, precision, char_e, hash_flag);
    len_result = s21_strlen(result);
    tmp = calloc(len_result, sizeof(char*));
    i = len_result;
    j = 0;
    while (i >= 0) {
      if (result[i] == '\0') {
        i--;
        continue;
      }
      tmp[j++] = result[i--];
      if (result[i] == 'e' || result[i] == 'E') {
        tmp[j++] = result[i--];
        break;
      }
    }
    for (; result[i] == '0'; i--)
      ;

    for (; i >= 0; i--, j++) tmp[j] = result[i];
    free_line(&result);
    result = reverse_str(tmp);
    free_line(&tmp);
  } else {
    long double expo = floorl(log10l(num));
    precision = precision - expo - 1 < 1 ? 1 : precision - expo - 1;
    result = s21_ftoa(num, precision, hash_flag);
    len_result = s21_strlen(result) - 1;
    for (; result[len_result] == '0'; len_result--) result[len_result] = 0;
    if (result[len_result] == '.') result[len_result] = 0;
  }
  return result;
}