#include "../unit_tests.h"

START_TEST(s21_strncat_1) {
  char str1[100] = "Hello world!";
  char str2[100] = "Bye";
  ck_assert_ptr_eq(strncat(str1, str2, 5), s21_strncat(str1, str2, 5));
}
END_TEST

START_TEST(s21_strncat_2) {
  char str1[100] = "Hello world!";
  char str2[100] = "BlackRat";
  ck_assert_ptr_eq(strncat(str1, str2, 7), s21_strncat(str1, str2, 7));
}
END_TEST

START_TEST(s21_strncat_3) {
  char str1[100] = "Hello world!";
  char str2[100] = "\0";
  ck_assert_ptr_eq(strncat(str1, str2, 7), s21_strncat(str1, str2, 7));
}
END_TEST

START_TEST(s21_strncat_4) {
  char str1[100] = "\0";
  char str2[100] = "Hello world!";
  ck_assert_ptr_eq(strncat(str1, str2, 3), s21_strncat(str1, str2, 3));
}
END_TEST

START_TEST(s21_strncat_5) {
  char str1[100] = "\0www";
  char str2[100] = "Hello world!";
  ck_assert_ptr_eq(strncat(str1, str2, 3), s21_strncat(str1, str2, 3));
}
END_TEST

START_TEST(s21_strncat_6) {
  char str1[100] = "";
  char str2[100] = "Hello world!";
  ck_assert_ptr_eq(strncat(str1, str2, 3), s21_strncat(str1, str2, 3));
}
END_TEST

START_TEST(s21_strncat_7) {
  char str1[100] = "Hello world!";
  char str2[100] = "";
  ck_assert_ptr_eq(strncat(str1, str2, 5), s21_strncat(str1, str2, 5));
}
END_TEST

Suite *s21_strncat_test(void) {
  Suite *s = suite_create("s21_strncat");
  TCase *tc = tcase_create("case_s21_strncat");

  tcase_add_test(tc, s21_strncat_1);
  tcase_add_test(tc, s21_strncat_2);
  tcase_add_test(tc, s21_strncat_3);
  tcase_add_test(tc, s21_strncat_4);
  tcase_add_test(tc, s21_strncat_5);
  tcase_add_test(tc, s21_strncat_6);
  tcase_add_test(tc, s21_strncat_7);

  suite_add_tcase(s, tc);
  return s;
}