#include "../unit_tests.h"

START_TEST(s21_strrchr_1) {
  char str1[100] = "";
  char str2 = 'O';

  ck_assert_ptr_eq(strrchr(str1, str2), s21_strrchr(str1, str2));
}
END_TEST

START_TEST(s21_strrchr_2) {
  char str1[100] = "Go, Johnny go, go, go!";
  char str2 = 'N';
  ck_assert_ptr_eq(strrchr(str1, str2), s21_strrchr(str1, str2));
}
END_TEST

START_TEST(s21_strrchr_3) {
  char str1[100] = "NEVER WAS A STORY OF MORE wOE";
  char str2 = 'w';
  ck_assert_str_eq(strrchr(str1, str2), s21_strrchr(str1, str2));
}
END_TEST

START_TEST(s21_strrchr_4) {
  char str1[100] = "one a two b tree c four d";
  char str2 = 'l';
  ck_assert_ptr_eq(strrchr(str1, str2), s21_strrchr(str1, str2));
}
END_TEST

START_TEST(s21_strrchr_5) {
  char str1[100] = "ThreeLittleNiggerBoysWalkingInTheZoo!!";
  char str2 = ' ';
  ck_assert_ptr_eq(strrchr(str1, str2), s21_strrchr(str1, str2));
}
END_TEST

START_TEST(s21_strrchr_6) {
  char str1[] = "abc";
  int n = '1';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(s21_strrchr_7) {
  char str1[] = "оарк";
  int n = '\\';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(s21_strrchr_8) {
  char str1[] = " ";
  int n = ' ';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(s21_strrchr_9) {
  char str1[] = " ";
  int n = '\\';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(s21_strrchr_10) {
  char str1[] = "021";
  int n = '0';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(s21_strrchr_11) {
  char str1[] = "ab\nc";
  int n = '\n';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(s21_strrchr_12) {
  char str1[] = "";
  int n = '\0';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(s21_strrchr_13) {
  char str1[] = "\0\0\0";
  int n = '\0';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

START_TEST(s21_strrchr_14) {
  char str1[] = "ab,c";
  int n = ',';
  ck_assert_ptr_eq(strrchr(str1, n), s21_strrchr(str1, n));
}
END_TEST

Suite *s21_strrchr_test(void) {
  Suite *s = suite_create("s21_strrchr");
  TCase *tc = tcase_create("case_s21_strrchr");

  tcase_add_test(tc, s21_strrchr_1);
  tcase_add_test(tc, s21_strrchr_2);
  tcase_add_test(tc, s21_strrchr_3);
  tcase_add_test(tc, s21_strrchr_4);
  tcase_add_test(tc, s21_strrchr_5);
  tcase_add_test(tc, s21_strrchr_6);
  tcase_add_test(tc, s21_strrchr_7);
  tcase_add_test(tc, s21_strrchr_8);
  tcase_add_test(tc, s21_strrchr_9);
  tcase_add_test(tc, s21_strrchr_10);
  tcase_add_test(tc, s21_strrchr_11);
  tcase_add_test(tc, s21_strrchr_12);
  tcase_add_test(tc, s21_strrchr_13);
  tcase_add_test(tc, s21_strrchr_14);

  suite_add_tcase(s, tc);
  return s;
}
