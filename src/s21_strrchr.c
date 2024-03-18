#include "s21_string.h"

char* s21_strrchr(const char* str, int c) {
  const char* ptr = str;
  int simbol = 0;

  while (*str) {
    str++;
  }
  while (str >= ptr) {
    if (*str == (char)c) {
      simbol = 1;
      break;
    }
    str--;
  }
  return simbol ? (char*)str : s21_NULL;
}
