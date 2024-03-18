#include "../unit_tests.h"

START_TEST(sprintf_1_u_minus) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *str3 = "Test %-u Test";
  unsigned int val = 012;
  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_1_u_L) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *str3 = "Test %Lu Test";
  unsigned int val = 012;
  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_1_x_h) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *str3 = "Test %hx Test";
  unsigned int val = 012;
  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_1_unsigned_o) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *str3 = "Test %ou Test";
  unsigned int val = 012;
  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_1_unsigned) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *str3 = "Test %u Test";
  unsigned int val = 012;
  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_1_unsigned_x) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *str3 = "Test %xu Test";
  unsigned int val = 012;
  int res1 = s21_sprintf(str1, str3, val);
  int res2 = sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_X_hash) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%#X", 33), sprintf(str2, "%#X", 33));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_X_l) {
  char str1[BUFF_SIZE] = {0};
  char str2[BUFF_SIZE] = {0};
  char *format = "%lX";
  ck_assert_int_eq(s21_sprintf(str1, format, 33), sprintf(str2, format, 33));
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *s21_sprintf_ouxX_test(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_sprintf_ouxX");
  tc = tcase_create("case_s21_sprintf_ouxX");

  tcase_add_test(tc, sprintf_1_u_minus);
  tcase_add_test(tc, sprintf_1_unsigned_o);
  tcase_add_test(tc, sprintf_1_unsigned);
  tcase_add_test(tc, sprintf_1_unsigned_x);

  tcase_add_test(tc, sprintf_1_u_L);
  tcase_add_test(tc, sprintf_1_x_h);
  tcase_add_test(tc, test_X_hash);
  tcase_add_test(tc, test_X_l);

  suite_add_tcase(s, tc);

  return s;
}