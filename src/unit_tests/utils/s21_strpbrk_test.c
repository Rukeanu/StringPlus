#include "../unit_tests.h"

START_TEST(s21_strpbrk_test_1) {
  char test_1[] = "Hello World";
  char test_2[] = "Wor";

  ck_assert_str_eq(s21_strpbrk(test_1, test_2), "o World");
  ck_assert_str_eq(s21_strpbrk(test_1, test_2), strpbrk(test_1, test_2));
}
END_TEST

START_TEST(s21_strpbrk_test_2) {
  char test_1[512] = "This is strpbrk  test";
  char test_2[512] = "is";

  ck_assert_str_eq(s21_strpbrk(test_1, test_2), strpbrk(test_1, test_2));
}
END_TEST

START_TEST(s21_strpbrk_test_3) {
  char *test_1 = "Thi is unit test";
  char *test_2 = "";
  char *test_3 = "T";
  char *test_4 = "e";

  ck_assert(s21_strpbrk(test_1, test_2) == NULL);
  ck_assert_uint_eq((unsigned long)s21_strpbrk(test_1, test_2),
                    (unsigned long)strpbrk(test_1, test_2));
  ck_assert_uint_eq((unsigned long)s21_strpbrk(test_1, test_3),
                    (unsigned long)strpbrk(test_1, test_3));
  ck_assert_uint_eq((unsigned long)s21_strpbrk(test_1, test_4),
                    (unsigned long)strpbrk(test_1, test_4));
}
END_TEST

Suite *s21_strpbrk_test(void) {
  Suite *s = suite_create("s21_strpbrk");
  TCase *tc = tcase_create("case_s21_strpbrk");

  tcase_add_test(tc, s21_strpbrk_test_1);
  tcase_add_test(tc, s21_strpbrk_test_2);
  tcase_add_test(tc, s21_strpbrk_test_3);

  suite_add_tcase(s, tc);

  return s;
}