#include "../unit_tests.h"

START_TEST(sprintf_spec_e_def_test_1) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%e";
  s21_sprintf(str1, format, 122e2);
  sprintf(str2, format, 122e2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_def_test_2) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%e";
  s21_sprintf(str1, format, 1.05e-5);
  sprintf(str2, format, 1.05e-5);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_def_test_3) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%e";
  s21_sprintf(str1, format, -122e-2);
  sprintf(str2, format, -122e-2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_def_test_4) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%e";
  s21_sprintf(str1, format, NAN);
  sprintf(str2, format, NAN);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_def_test_5) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%e";
  s21_sprintf(str1, format, 1.0 / 0.0);
  sprintf(str2, format, 1.0 / 0.0);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_def_test_6) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%E";
  s21_sprintf(str1, format, -122e-2);
  sprintf(str2, format, -122e-2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *s21_sprintf_e_test(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_sprintf_e");

  tc = tcase_create("case_s21_sprintf_e");

  tcase_add_test(tc, sprintf_spec_e_def_test_1);
  tcase_add_test(tc, sprintf_spec_e_def_test_2);
  tcase_add_test(tc, sprintf_spec_e_def_test_3);
  tcase_add_test(tc, sprintf_spec_e_def_test_4);
  tcase_add_test(tc, sprintf_spec_e_def_test_5);
  tcase_add_test(tc, sprintf_spec_e_def_test_6);

  suite_add_tcase(s, tc);

  return s;
}