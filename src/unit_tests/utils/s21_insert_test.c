#include "unit_tests.h"

START_TEST(empty_str) {
  char s21_str[] = "Oh";
  char s21_src[] = "";
  s21_size_t index = 3;

  void *result = s21_insert(s21_src, s21_str, index);
  ck_assert_pstr_eq(result, s21_NULL);
}
END_TEST

START_TEST(simple_test) {
  char s21_str[] = "my ";
  char s21_src[] = "Hello world";
  s21_size_t index = 6;

  void *result = s21_insert(s21_src, s21_str, index);
  ck_assert_pstr_eq(result, "Hello my world");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(empty_test) {
  char s21_str[] = "he";
  char s21_src[] = "";
  s21_size_t index = 0;

  void *result = s21_insert(s21_src, s21_str, index);
  ck_assert_pstr_eq(result, "he");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(endi_test) {
  char s21_str[] = " try";
  char s21_src[] = "Good";
  s21_size_t index = 4;
  void *result = s21_insert(s21_src, s21_str, index);
  ck_assert_pstr_eq(result, "Good try");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(starti_test) {
  char s21_str[] = "School";
  char s21_src[] = "42";
  s21_size_t index = 0;
  void *result = s21_insert(s21_src, s21_str, index);
  ck_assert_pstr_eq(result, "School42");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

START_TEST(zero_test) {
  char *s21_str = s21_NULL;
  char s21_src[] = "Some here";
  s21_size_t index = 0;
  void *result = s21_insert(s21_src, s21_str, index);
  ck_assert_pstr_eq(result, s21_NULL);
}
END_TEST

START_TEST(zero_test2) {
  char s21_str[] = "Some here";
  char *s21_src = s21_NULL;
  s21_size_t index = 0;
  void *result = s21_insert(s21_src, s21_str, index);
  ck_assert_pstr_eq(result, s21_NULL);
}
END_TEST

START_TEST(middle_test) {
  char s21_str[] = "ret";
  char s21_src[] = "consectetur";
  s21_size_t index = 6;
  void *result = s21_insert(s21_src, s21_str, index);
  ck_assert_pstr_eq(result, "consecrettetur");
  if (result != s21_NULL) {
    free(result);
  }
}
END_TEST

Suite *s21_insert_test(void) {
  Suite *s = suite_create("s21_insert");
  TCase *tc = tcase_create("case_s21_insert");

  tcase_add_test(tc, empty_str);
  tcase_add_test(tc, simple_test);
  tcase_add_test(tc, empty_test);
  tcase_add_test(tc, endi_test);
  tcase_add_test(tc, starti_test);
  tcase_add_test(tc, zero_test);
  tcase_add_test(tc, zero_test2);
  tcase_add_test(tc, middle_test);

  suite_add_tcase(s, tc);

  return s;
}