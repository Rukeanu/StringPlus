#include "../unit_tests.h"

START_TEST(s21_trim_1) {
  char src[] = " Hello world! ";
  char chars_trim[] = " ";
  char *res = "Hello world!";
  char *str_trim = s21_trim(src, chars_trim);
  ck_assert_str_eq(str_trim, res);
  free(str_trim);
}
END_TEST

START_TEST(s21_trim_2) {
  char src[] = "   Hello world   ";
  char chars_trim[] = " ";
  char *res = "Hello world";
  char *str_trim = s21_trim(src, chars_trim);
  ck_assert_str_eq(str_trim, res);
  free(str_trim);
}
END_TEST

START_TEST(s21_trim_3) {
  char src[] = "dhdjdjajdadh@#@#@#@#@##@";
  char chars_trim[] = "@:Q:Q:Q:Q:;";
  char *res = "dhdjdjajdadh@#@#@#@#@##";
  char *str_trim = s21_trim(src, chars_trim);
  ck_assert_str_eq(str_trim, res);
  free(str_trim);
}
END_TEST

Suite *s21_trim_test(void) {
  Suite *s = suite_create("s21_trim");
  TCase *tc = tcase_create("case_s21_trim");

  tcase_add_test(tc, s21_trim_1);
  tcase_add_test(tc, s21_trim_2);
  tcase_add_test(tc, s21_trim_3);

  suite_add_tcase(s, tc);
  return s;
}
