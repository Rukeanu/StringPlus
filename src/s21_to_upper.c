#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *res = s21_NULL;

  if (str == s21_NULL) {
    res = s21_NULL;
  } else if (str != s21_NULL) {
    size_t length = 0;
    while (str[length] != '\0') {
      length++;
    }
    res = (char *)malloc(length + 1);
    if (res == s21_NULL) {
      res = s21_NULL;
    } else {
      for (size_t i = 0; i < length; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          res[i] = str[i] - ('a' - 'A');
        } else {
          res[i] = str[i];
        }
      }
      res[length] = '\0';
    }
  }
  return res;
}