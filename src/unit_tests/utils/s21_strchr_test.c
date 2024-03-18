#include "../unit_tests.h"

START_TEST(s21_strchr_test_1) {
  char test_1[] = "0123456789";
  int sym1 = '1';
  char *ach1 = s21_strchr(test_1, sym1);
  ck_assert_str_eq(ach1, "123456789");

  char test_2[] = "0123456789";
  int sym2 = '1';
  char *ach2 = strchr(test_2, sym2);
  ck_assert_str_eq(ach1, ach2);
  ck_assert_str_eq(test_1, test_2);
}
END_TEST

START_TEST(s21_strchr_test_2) {
  char test_1[] = "ABCDE";
  int sym1 = '\0';
  char *ach1 = s21_strchr(test_1, sym1);

  char test_2[] = "ABCDE";
  int sym2 = '\0';
  char *ach2 = strchr(test_2, sym2);

  ck_assert_str_eq(ach1, ach2);
  ck_assert_str_eq(test_1, test_2);
}
END_TEST

START_TEST(s21_strchr_test_3) {
  char test_1[512] = "abcdefg";
  int sym1 = 'a';
  char *ach1 = s21_strchr(test_1, sym1);

  char test_2[512] = "abcdefg";
  int sym2 = 'a';
  char *ach2 = s21_strchr(test_2, sym2);

  ck_assert_str_eq(ach1, ach2);
  ck_assert_str_eq(test_1, test_2);
}

Suite *s21_strchr_test(void) {
  Suite *s = suite_create("s21_strchr");
  TCase *tc = tcase_create("case_s21_strchr");

  tcase_add_test(tc, s21_strchr_test_1);
  tcase_add_test(tc, s21_strchr_test_2);
  tcase_add_test(tc, s21_strchr_test_3);

  suite_add_tcase(s, tc);

  return s;
}