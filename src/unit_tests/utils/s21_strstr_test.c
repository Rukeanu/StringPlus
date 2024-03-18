#include "../unit_tests.h"

START_TEST(s21_strstr_1) {
  char str1[] = "1234";
  char str2[] = "123";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_2) {
  char str1[] = "132";
  char str2[] = "1234";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_3) {
  char str1[] = "ab12";
  char str2[] = "12\0ab";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_4) {
  char *str1;
  char *str2;
  str1 = "ab\012";
  str2 = "1\02ab";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_5) {
  char str1[100] = "killer queen byte dust";
  char str2[100] = "que";
  char *res1;
  char *res2;
  res1 = strstr(str1, str2);
  res2 = s21_strstr(str1, str2);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strstr_6) {
  char str1[] = "abC";
  char str2[] = "abc";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_7) {
  char str1[100] = "Go, Johnny go, go, go!";
  char str2[100] = "Joh";
  char *res1;
  char *res2;
  res1 = strstr(str1, str2);
  res2 = s21_strstr(str1, str2);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strstr_8) {
  char str1[] = "ABC";
  char str2[] = "abc";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_9) {
  char str1[] = "abc";
  char str2[] = "ABC";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_10) {
  char str1[100] = "wonder of you";
  char str2[100] = "shine";
  char *res1;
  char *res2;
  res1 = strstr(str1, str2);
  res2 = s21_strstr(str1, str2);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(s21_strstr_11) {
  char str1[] = "a b c";
  char str2[] = "abc";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_12) {
  char str1[] = "abc";
  char str2[] = "a b c";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_13) {
  char str1[100] = "Go, Johnny go, go, go!";
  char str2[100] = "go";
  char *res1;
  char *res2;
  res1 = strstr(str1, str2);
  res2 = s21_strstr(str1, str2);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(s21_strstr_14) {
  char str1[] = " ";
  char str2[] = "abc";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_15) {
  char str1[] = "abc";
  char str2[] = " ";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_16) {
  char str1[] = "9087";
  char str2[] = "657";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_17) {
  char str1[] = " ";
  char str2[] = " ";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_18) {
  char str1[] = "123";
  char str2[] = "321";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_19) {
  char str1[] = "321";
  char str2[] = "321";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_20) {
  char str1[] = "";
  char str2[] = "1\02ab";
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_21) {
  char str1[100] = "Sunny";
  char str2[100] = "";
  char *res1;
  char *res2;
  res1 = strstr(str1, str2);
  res2 = s21_strstr(str1, str2);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

Suite *s21_strstr_test(void) {
  Suite *s = suite_create("s21_strstr");
  TCase *tc = tcase_create("case_s21_strstr");

  tcase_add_test(tc, s21_strstr_1);
  tcase_add_test(tc, s21_strstr_2);
  tcase_add_test(tc, s21_strstr_3);
  tcase_add_test(tc, s21_strstr_4);
  tcase_add_test(tc, s21_strstr_5);
  tcase_add_test(tc, s21_strstr_6);
  tcase_add_test(tc, s21_strstr_7);
  tcase_add_test(tc, s21_strstr_8);
  tcase_add_test(tc, s21_strstr_9);
  tcase_add_test(tc, s21_strstr_10);
  tcase_add_test(tc, s21_strstr_11);
  tcase_add_test(tc, s21_strstr_12);
  tcase_add_test(tc, s21_strstr_13);
  tcase_add_test(tc, s21_strstr_14);
  tcase_add_test(tc, s21_strstr_15);
  tcase_add_test(tc, s21_strstr_16);
  tcase_add_test(tc, s21_strstr_17);
  tcase_add_test(tc, s21_strstr_18);
  tcase_add_test(tc, s21_strstr_19);
  tcase_add_test(tc, s21_strstr_20);
  tcase_add_test(tc, s21_strstr_21);

  suite_add_tcase(s, tc);
  return s;
}