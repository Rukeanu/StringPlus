#include "s21_string.h"

int is_trim_char(char c, const char *trim_chars) {
  int result = 0;

  if (trim_chars != s21_NULL) {
    size_t trim_chars_length = custom_strlen(trim_chars);
    size_t i = 0;

    while (i < trim_chars_length) {
      if (c == trim_chars[i]) {
        result = 1;
        break;
      }
      i++;
    }
  }

  return result;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == s21_NULL || trim_chars == s21_NULL) {
    return s21_NULL;
  }

  size_t src_length = custom_strlen(src);
  size_t start_index = 0;
  while (src[start_index] != '\0' &&
         is_trim_char(src[start_index], trim_chars)) {
    ++start_index;
  }
  if (src[start_index] == '\0') {
    char *empty_result = (char *)malloc(1);
    if (empty_result == s21_NULL) {
      return s21_NULL;
    }
    empty_result[0] = '\0';
    return empty_result;
  }
  size_t end_index = src_length - 1;
  while (end_index > start_index && is_trim_char(src[end_index], trim_chars)) {
    --end_index;
  }
  size_t result_length = end_index - start_index + 1;
  char *result = (char *)malloc(result_length + 1);
  if (result == NULL) {
    return NULL;
  }
  for (size_t i = 0; i < result_length; ++i) {
    result[i] = src[start_index + i];
  }

  result[result_length] = '\0';

  return result;
}
