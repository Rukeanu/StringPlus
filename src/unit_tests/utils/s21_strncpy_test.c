#include "../unit_tests.h"

START_TEST(strncpy_test1) {
  char dest[20] = "abrakadabra";
  const char src[] = "Copy me!";
  s21_strncpy(dest, src, 20);
  ck_assert_str_eq(dest, src);
}
END_TEST

START_TEST(strncpy_test2) {
  char dest[20] = " ";
  const char src[] = "Copy me!";
  s21_strncpy(dest, src, 20);
  ck_assert_str_eq(dest, src);
}
END_TEST

START_TEST(strncpy_test3) {
  char dest[20] = "";
  const char src[] = "";
  s21_strncpy(dest, src, 5);
  ck_assert_str_eq(dest, src);
}
END_TEST

START_TEST(strncpy_test4) {
  char dest[20] = "";
  const char src[] = "aaa";
  s21_strncpy(dest, src, 5);
  ck_assert_str_eq(dest, src);
}
END_TEST

START_TEST(strncpy_test5) {
  char dest[6] = "";
  const char src[] = "aaabbb";
  char *result = s21_strncpy(dest, src, 5);
  ck_assert_str_eq(result, "aaabb");
}
END_TEST

START_TEST(strncpy_test6) {
  char dest[5] = "";
  const char src[] = "aaabbb";
  s21_strncpy(dest, src, 1);
  ck_assert_str_eq(dest, "a");
}
END_TEST

START_TEST(strncpy_test7) {
  char dest[20] = "";
  const char src[] = "aaa";
  char *result = s21_strncpy(dest, src, -1);
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(strncpy_test8) {
  char dest[20] = "eee";
  const char src[] = "";
  s21_strncpy(dest, src, 5);
  ck_assert_str_eq(dest, src);
}
END_TEST

START_TEST(strncpy_test9) {
  char dest[20] = "eee";
  const char src[] = "a";

  char dest_orig[20] = "eee";
  const char src_orig[] = "a";
  s21_strncpy(dest, src, 1);
  strncpy(dest_orig, src_orig, 1);
  ck_assert_str_eq(dest, dest_orig);
}
END_TEST

START_TEST(strncpy_test10) {
  char dest[20] = "eee";
  const char src[] = "a";
  char *result = s21_strncpy(dest, src, 0);
  ck_assert_str_eq(dest, result);
}
END_TEST

START_TEST(strncpy_test11) {
  char dest[20] = "eee";
  const char src[] = "a";
  s21_strncpy(dest, src, 5);
  ck_assert_str_eq(dest, src);
}
END_TEST

Suite *s21_strncpy_test(void) {
  Suite *s = suite_create("s21_strncpy");
  TCase *tc = tcase_create("case_s21_strncpy");

  tcase_add_test(tc, strncpy_test1);
  tcase_add_test(tc, strncpy_test2);
  tcase_add_test(tc, strncpy_test3);
  tcase_add_test(tc, strncpy_test4);
  tcase_add_test(tc, strncpy_test5);
  tcase_add_test(tc, strncpy_test6);
  tcase_add_test(tc, strncpy_test7);
  tcase_add_test(tc, strncpy_test8);
  tcase_add_test(tc, strncpy_test9);
  tcase_add_test(tc, strncpy_test10);
  tcase_add_test(tc, strncpy_test11);

  suite_add_tcase(s, tc);
  return s;
}
