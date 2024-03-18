#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *res = s21_NULL;

  if (str == s21_NULL) {
    return s21_NULL;
  } else if (str != s21_NULL) {
    size_t length = 0;
    while (str[length] != '\0') {
      length++;
    }
    res = (char *)malloc(length + 1);
    if (res == s21_NULL) {
      res = s21_NULL;
    }
    for (size_t i = 0; i < length; i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        res[i] = str[i] + ('a' - 'A');
      } else {
        res[i] = str[i];
      }
    }
    res[length] = '\0';
  }
  return res;
}