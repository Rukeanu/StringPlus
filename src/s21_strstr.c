#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  const char *h, *n;
  for (; *haystack != '\0'; haystack++) {
    h = haystack;
    n = needle;
    while (*n != '\0' && *h == *n) {
      h++;
      n++;
    }
    if (*n == '\0') {
      return (char *)haystack;
    }
  }
  return s21_NULL;
}
