#include "s21_string.h"

char *s21_strncpy(char *destination, const char *src, s21_size_t n) {
  if (n > 9223372036854775807) {
    return s21_NULL;
  }
  s21_size_t src_len = s21_strlen(src);
  for (s21_size_t idx = 0; idx < n; idx++) {
    if (idx < src_len) {
      destination[idx] = src[idx];
    } else {
      destination[idx] = '\0';
    }
  }
  return destination;
}
