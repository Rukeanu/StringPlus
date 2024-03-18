#include "../unit_tests.h"

START_TEST(lower_test1) {
  const char *input = "ABRA KADABRA";
  const char *expect = "abra kadabra";

  char *res = s21_to_lower(input);
  ck_assert_str_eq(res, expect);
  free(res);
}
END_TEST

START_TEST(lower_test2) {
  const char str1[13] = "ABRA KADABRA";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "abra kadabra");
  free(str2);
}
END_TEST

START_TEST(lower_test3) {
  const char str1[20] = "HELLO\0oooo";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "hello");
  free(str2);
}
END_TEST

START_TEST(lower_test4) {
  const char str1[15] = "";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

START_TEST(lower_test5) {
  const char str1[20] = "    ";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "    ");
  free(str2);
}
END_TEST

START_TEST(lower_test6) {
  const char str1[80] = "74^&$#@%12$!#%@#^8780";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "74^&$#@%12$!#%@#^8780");
  if (str2) free(str2);
}

START_TEST(lower_test7) {
  const char str1[80] = "74^&$#@%12$!#%@#^8780";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "74^&$#@%12$!#%@#^8780");
  if (str2) free(str2);
}

START_TEST(lower_test8) {
  const char str1[80] = "HELLO\nWORLD";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "hello\nworld");
  if (str2) free(str2);
}

START_TEST(lower_test9) {
  const char *test_str = "My Name Is";

  char *func_res = s21_to_lower(test_str);
  ck_assert_str_eq(func_res, "my name is");
  free(func_res);
}
END_TEST

START_TEST(lower_test10) {
  const char *test_str = "My Name 1s";

  char *func_res = s21_to_lower(test_str);
  ck_assert_str_eq(func_res, "my name 1s");
  free(func_res);
}
END_TEST

START_TEST(lower_test11) {
  const char *test_str = "my name is";

  char *func_res = s21_to_lower(test_str);
  ck_assert_str_eq(func_res, "my name is");
  free(func_res);
}
END_TEST

Suite *s21_to_lower_test(void) {
  Suite *s = suite_create("s21_to_lower");
  TCase *tc = tcase_create("case_s21_to_lower");

  tcase_add_test(tc, lower_test1);
  tcase_add_test(tc, lower_test2);
  tcase_add_test(tc, lower_test3);
  tcase_add_test(tc, lower_test4);
  tcase_add_test(tc, lower_test5);
  tcase_add_test(tc, lower_test6);
  tcase_add_test(tc, lower_test7);
  tcase_add_test(tc, lower_test8);
  tcase_add_test(tc, lower_test9);
  tcase_add_test(tc, lower_test10);
  tcase_add_test(tc, lower_test11);

  suite_add_tcase(s, tc);

  return s;
}