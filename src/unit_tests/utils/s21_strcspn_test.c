#include "../unit_tests.h"

START_TEST(s21_strcspn_test_1) {
  char test_1[512] = "0123456789";
  char test_2[512] = "9876";

  ck_assert_uint_eq(s21_strcspn(test_1, test_2), strcspn(test_1, test_2));
}
END_TEST

START_TEST(s21_strcspn_test_2) {
  char test_1[512] = "HelloWorld";
  char test_2[512] = "Hello";

  ck_assert_uint_eq(s21_strcspn(test_1, test_2), strcspn(test_1, test_2));
}
END_TEST

START_TEST(s21_strcspn_test_3) {
  char test_1[512] = "Hello World";
  char test_2[512] = "World";

  ck_assert_uint_eq(s21_strcspn(test_1, test_2), strcspn(test_1, test_2));
}
END_TEST

START_TEST(s21_strcspn_test_4) {
  char test_1[512] = "HelloWorld";
  char test_2[512] = "0/";

  ck_assert_uint_eq(s21_strcspn(test_1, test_2), strcspn(test_1, test_2));
}
END_TEST

START_TEST(s21_strcspn_test_5) {
  char test_1[512] = "0123456789";
  char test_2[512] = " ";

  ck_assert_uint_eq(s21_strcspn(test_1, test_2), strcspn(test_1, test_2));
}
END_TEST

START_TEST(s21_strcspn_test_6) {
  char test_1[512] = "HelloWorld";
  char test_2[512] = " ";

  ck_assert_uint_eq(s21_strcspn(test_1, test_2), strcspn(test_1, test_2));
}

Suite *s21_strcspn_test(void) {
  Suite *s = suite_create("s21_strcspn");
  TCase *tc = tcase_create("case_s21_strcspn");

  tcase_add_test(tc, s21_strcspn_test_1);
  tcase_add_test(tc, s21_strcspn_test_2);
  tcase_add_test(tc, s21_strcspn_test_3);
  tcase_add_test(tc, s21_strcspn_test_4);
  tcase_add_test(tc, s21_strcspn_test_5);
  tcase_add_test(tc, s21_strcspn_test_6);

  suite_add_tcase(s, tc);

  return s;
}