#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *token = s21_NULL;

  if (str != s21_NULL) token = str;

  while (token != s21_NULL && *token && s21_strchr(delim, *token)) token++;

  char *start = token;
  if (token != s21_NULL) {
    if (*token == '\0') start = s21_NULL;

    while (*token && !s21_strchr(delim, *token)) token++;

    if (*token != '\0') *token++ = '\0';
  }
  return start;
}
