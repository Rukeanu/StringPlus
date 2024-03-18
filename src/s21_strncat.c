#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  if (n > 0 && src) {
    s21_size_t sizeDest = s21_strlen(dest);
    for (s21_size_t i = 0; i < n; i++) {
      *(dest + sizeDest + i) = *(src + i);
    }
  }
  return dest;
}