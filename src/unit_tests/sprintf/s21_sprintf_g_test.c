#include "../unit_tests.h"

START_TEST(sprintf_2_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\n%g\n%.0g\n%4g\n%4.g\n%5.10g!";
  double a = -764231539.;
  int s21_res = s21_sprintf(s21_str, format, a, a, a, a, a);
  int res = sprintf(str, format, a, a, a, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_3_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\n%#g\n%#.g\n%#5.g\n%#.0g\n%#0.0g!";
  double a = -665695342471359.;
  int s21_res = s21_sprintf(s21_str, format, a, a, a, a, a);
  int res = sprintf(str, format, a, a, a, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_4_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nNew test: %020g\nSecond test: %020.g!";
  double a = -5921563224775967.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_5_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nThird test: %010g\nForth test: %010.g!";
  double a = -5921563224775967.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_6_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nFifth test: %0.0g!";
  double a = -5921563224775967.;
  int s21_res = s21_sprintf(s21_str, format, a);
  int res = sprintf(str, format, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_7_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nNew test: %020g\nSecond test: %020.g!";
  double a =
      -592156322477597777777777777777777777777777777777777777777777777777777777777777777777776.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_8_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nThird test: %010g\nForth test: %010.g\nFifth test:%0.0g!";
  double a =
      -592156322477597777777777777777777777777777777777777777777777777777777777777777777777776.;
  int s21_res = s21_sprintf(s21_str, format, a, a, a);
  int res = sprintf(str, format, a, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_9_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nNew test: %020g\nSecond test: %020.5g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_10_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nThird test: %020.4g\nForth test: %020.3g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_11_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nFifth test: %020.2g\nSixth test: %020.1g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_12_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nSeventh test: %020.g\n Eighth test: %020.0g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_13_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nNew test: % 21g\nSecond test: % 21.5g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_14_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nThird test: % 20.4g\nForth test: % 20.3g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_15_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nFifth test: % 20.2g\nSixth test: % 20.1g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_16_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nSeventh test: % 20.g\n Eighth test: % 20.0g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_17_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nNew test: % 31g\nSecond test: % 30.5g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_18_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nThird test: % 33.4g\nForth test: % 35.3g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_19_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nFifth test: % 36.2g\nSixth test: % 45.1g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_20_g) {
  char s21_str[BUFF_SIZE] = {0};
  char str[BUFF_SIZE] = {0};
  char *format = "\nSeventh test: % 64.g\n Eighth test: % 80.0g!";
  double a = -592156322477596.;
  int s21_res = s21_sprintf(s21_str, format, a, a);
  int res = sprintf(str, format, a, a);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

Suite *s21_sprintf_g_test(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_sprintf_g");

  tc = tcase_create("case_s21_sprintf_g");

  tcase_add_test(tc, sprintf_2_g);
  tcase_add_test(tc, sprintf_3_g);
  tcase_add_test(tc, sprintf_4_g);
  tcase_add_test(tc, sprintf_5_g);
  tcase_add_test(tc, sprintf_6_g);
  tcase_add_test(tc, sprintf_7_g);
  tcase_add_test(tc, sprintf_8_g);
  tcase_add_test(tc, sprintf_9_g);
  tcase_add_test(tc, sprintf_10_g);
  tcase_add_test(tc, sprintf_11_g);
  tcase_add_test(tc, sprintf_12_g);
  tcase_add_test(tc, sprintf_13_g);
  tcase_add_test(tc, sprintf_14_g);
  tcase_add_test(tc, sprintf_15_g);
  tcase_add_test(tc, sprintf_16_g);
  tcase_add_test(tc, sprintf_17_g);
  tcase_add_test(tc, sprintf_18_g);
  tcase_add_test(tc, sprintf_19_g);
  tcase_add_test(tc, sprintf_20_g);

  suite_add_tcase(s, tc);

  return s;
}