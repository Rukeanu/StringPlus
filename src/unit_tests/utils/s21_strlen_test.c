#include "../unit_tests.h"

START_TEST(s21_strlen_1) {
  char *str = "Hello world";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_2) {
  char *str = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_3) {
  char *str = "q";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_4) {
  char *str = "qq";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

Suite *s21_strlen_test(void) {
  Suite *s = suite_create("s21_strlen");
  TCase *tc = tcase_create("case_s21_strlen");
  tcase_add_test(tc, s21_strlen_1);
  tcase_add_test(tc, s21_strlen_2);
  tcase_add_test(tc, s21_strlen_3);
  tcase_add_test(tc, s21_strlen_4);
  suite_add_tcase(s, tc);
  return s;
}