#include "../unit_tests.h"

START_TEST(s21_memcpy_test_1) {
  char test_1[512] = "MEMETEST";
  char test_2[512] = "  ";

  ck_assert_str_eq(s21_memcpy(test_1, test_2, 2), memcpy(test_1, test_2, 2));
}
END_TEST

START_TEST(s21_memcpy_test_2) {
  char test_1[512] = "///  ";
  char test_2[512] = "  & ///";

  ck_assert_str_eq(s21_memcpy(test_1, test_2, 6), memcpy(test_1, test_2, 6));
}
END_TEST

START_TEST(s21_memcpy_test_3) {
  char test_1[512] = "";
  char test_2[512] = "3456765";

  ck_assert_str_eq(s21_memcpy(test_1, test_2, 4), memcpy(test_1, test_2, 4));
}
END_TEST

START_TEST(s21_memcpy_test_4) {
  char test_1[512] = "3456765";
  char test_2[512] = "4789/2345";

  ck_assert_str_eq(s21_memcpy(test_1, test_2, 4), memcpy(test_1, test_2, 4));
}
END_TEST

START_TEST(s21_memcpy_test_5) {
  char test_1[512] = "";
  char test_2[512] = "";

  ck_assert_str_eq(s21_memcpy(test_1, test_2, 1), memcpy(test_1, test_2, 1));
}
END_TEST

START_TEST(s21_memcpy_test_6) {
  char test_1[512] = "1";
  char test_2[512] = "1";

  ck_assert_str_eq(s21_memcpy(test_1, test_2, 1), memcpy(test_1, test_2, 1));
}
END_TEST

Suite *s21_memcpy_test(void) {
  Suite *s = suite_create("s21_memcpy");
  TCase *tc = tcase_create("case_s21_memcpy");

  tcase_add_test(tc, s21_memcpy_test_1);
  tcase_add_test(tc, s21_memcpy_test_2);
  tcase_add_test(tc, s21_memcpy_test_3);
  tcase_add_test(tc, s21_memcpy_test_4);
  tcase_add_test(tc, s21_memcpy_test_5);
  tcase_add_test(tc, s21_memcpy_test_6);

  suite_add_tcase(s, tc);

  return s;
}