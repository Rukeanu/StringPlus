#include "../unit_tests.h"

START_TEST(upper_test1) {
  const char *input = "Abra Kadabra";
  const char *expect = "ABRA KADABRA";

  char *res = s21_to_upper(input);
  ck_assert_str_eq(res, expect);

  free(res);
}
END_TEST

START_TEST(upper_test2) {
  const char str1[15] = "dangeon Master";
  char *str2 = s21_to_upper(str1);

  ck_assert_str_eq(str2, "DANGEON MASTER");
  free(str2);
}
END_TEST

START_TEST(upper_test3) {
  const char str1[20] = "hello\0oooo";
  char *str2 = s21_to_upper(str1);

  ck_assert_str_eq(str2, "HELLO");
  free(str2);
}
END_TEST

START_TEST(upper_test4) {
  const char str1[15] = "";
  char *str2 = s21_to_upper(str1);

  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

START_TEST(upper_test5) {
  const char str1[20] = "\0HELLO";
  char *str2 = s21_to_upper(str1);

  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

START_TEST(upper_test6) {
  const char *test_str0 = "hello world";
  const char *test_str1 = "h1e2l3l4o5";

  char *func_res0 = s21_to_upper(test_str0);
  char *func_res1 = s21_to_upper(test_str1);

  ck_assert_str_eq(func_res0, "HELLO WORLD");
  ck_assert_str_eq(func_res1, "H1E2L3L4O5");
  free(func_res0);
  free(func_res1);
}
END_TEST

START_TEST(upper_test7) {
  const char *test_str = "h!e1l/l&o.";

  char *func_res = s21_to_upper(test_str);
  ck_assert_str_eq(func_res, "H!E1L/L&O.");
  free(func_res);
}
END_TEST

START_TEST(upper_test8) {
  const char *test_str = "HELLO";

  char *func_res = s21_to_upper(test_str);
  ck_assert_str_eq(func_res, test_str);
  free(func_res);
}
END_TEST

Suite *s21_to_upper_test(void) {
  Suite *s = suite_create("s21_to_upper");
  TCase *tc = tcase_create("case_s21_to_upper");

  tcase_add_test(tc, upper_test1);
  tcase_add_test(tc, upper_test2);
  tcase_add_test(tc, upper_test3);
  tcase_add_test(tc, upper_test4);
  tcase_add_test(tc, upper_test5);
  tcase_add_test(tc, upper_test6);
  tcase_add_test(tc, upper_test7);
  tcase_add_test(tc, upper_test8);

  suite_add_tcase(s, tc);

  return s;
}