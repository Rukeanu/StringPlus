#include "../unit_tests.h"

START_TEST(zero_byte) {
  char str1[] = "aboba";
  char str2[] = "aboba";
  int n = 0;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(first_byte_in_string) {
  char str1[] = "aboba";
  char str2[] = "aboba";
  int n = 3;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(register_test) {
  char str1[] = "aboba";
  char str2[] = "Aboba";
  int n = 1;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(zero_byte_in_num) {
  char str1[] = "1";
  char str2[] = "1";
  int n = 0;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(first_byte_in_num) {
  char str1[] = "1";
  char str2[] = "1234";
  int n = 1;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(two_byte_in_num) {
  char str1[] = "1234";
  char str2[] = "1234";
  int n = 2;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(eq_long_string) {
  char str1[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
  char str2[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
  int n = 71;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

Suite *s21_memcmp_test(void) {
  Suite *s = suite_create("s21_memcmp");
  TCase *tc = tcase_create("case_s21_memcmp");
  tcase_add_test(tc, zero_byte);
  tcase_add_test(tc, first_byte_in_string);
  tcase_add_test(tc, register_test);
  tcase_add_test(tc, zero_byte_in_num);
  tcase_add_test(tc, first_byte_in_num);
  tcase_add_test(tc, two_byte_in_num);
  tcase_add_test(tc, eq_long_string);

  suite_add_tcase(s, tc);
  return s;
}