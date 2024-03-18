#include "../unit_tests.h"

START_TEST(sprintf_spec_f_def_test_0) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%f";
  const float f1 = 0.21098;
  ck_assert_int_eq(s21_sprintf(str1, format, f1), sprintf(str2, format, f1));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_def_test_1) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%*f";
  ck_assert_int_eq(s21_sprintf(str1, format, 5, 122.87654321098),
                   sprintf(str2, format, 5, 122.87654321098));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_def_test_2) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%.*f";
  ck_assert_int_eq(s21_sprintf(str1, format, 5, 122.87654321098),
                   sprintf(str2, format, 5, 122.87654321098));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_def_test_3) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%f";
  ck_assert_int_eq(s21_sprintf(str1, format, 2.05),
                   sprintf(str2, format, 2.05));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_def_test_4) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%.f";
  ck_assert_int_eq(s21_sprintf(str1, format, 2.51),
                   sprintf(str2, format, 2.51));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_def_test_5) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%.1f";
  ck_assert_int_eq(s21_sprintf(str1, format, 2.05),
                   sprintf(str2, format, 2.05));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_def_test_6) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%f";
  s21_sprintf(str1, format, NAN);
  sprintf(str2, format, NAN);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_def_test_7) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%f";
  s21_sprintf(str1, format, POS_INF);
  sprintf(str2, format, POS_INF);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_def_test_8) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  const char *format = "%f";
  s21_sprintf(str1, format, NEG_INF);
  sprintf(str2, format, NEG_INF);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *s21_sprintf_f_test(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_sprintf_f");

  tc = tcase_create("case_s21_sprintf_f");

  tcase_add_test(tc, sprintf_spec_f_def_test_0);
  tcase_add_test(tc, sprintf_spec_f_def_test_1);
  tcase_add_test(tc, sprintf_spec_f_def_test_2);
  tcase_add_test(tc, sprintf_spec_f_def_test_3);
  tcase_add_test(tc, sprintf_spec_f_def_test_4);
  tcase_add_test(tc, sprintf_spec_f_def_test_5);
  tcase_add_test(tc, sprintf_spec_f_def_test_6);
  tcase_add_test(tc, sprintf_spec_f_def_test_7);
  tcase_add_test(tc, sprintf_spec_f_def_test_8);

  suite_add_tcase(s, tc);

  return s;
}