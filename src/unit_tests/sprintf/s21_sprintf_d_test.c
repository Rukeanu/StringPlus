#include "../unit_tests.h"

START_TEST(sprintf_spec_d_simple) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%d";
  ck_assert_int_eq(s21_sprintf(str1, format, 5), sprintf(str2, format, 5));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_zero) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%010d";
  ck_assert_int_eq(s21_sprintf(str1, format, 10), sprintf(str2, format, 10));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_dot) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%.10d";
  ck_assert_int_eq(s21_sprintf(str1, format, 10), sprintf(str2, format, 10));
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *s21_sprintf_d_test(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_sprintf_d");

  tc = tcase_create("case_s21_sprintf_d");

  tcase_add_test(tc, sprintf_spec_d_simple);
  tcase_add_test(tc, sprintf_spec_d_zero);
  tcase_add_test(tc, sprintf_spec_d_dot);

  suite_add_tcase(s, tc);

  return s;
}