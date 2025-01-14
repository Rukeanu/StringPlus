#include "../unit_tests.h"

START_TEST(sprintf_spec_c_default_test_1) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  ck_assert_int_eq(s21_sprintf(str1, "%c", 'z'), sprintf(str2, "%c", 'z'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_default_test_2) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  ck_assert_int_eq(s21_sprintf(str1, "%c", 122), sprintf(str2, "%c", 122));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_default_test_3) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  ck_assert_int_eq(s21_sprintf(str1, "%c", 0x7a), sprintf(str2, "%c", 0x7a));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_default_test_4) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  ck_assert_int_eq(s21_sprintf(str1, "%combie", 'z'),
                   sprintf(str2, "%combie", 'z'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_test_1) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  ck_assert_int_eq(s21_sprintf(str1, "%c", 'z'), sprintf(str2, "%c", 'z'));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_spec_c_flags_test_2) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  ck_assert_int_eq(s21_sprintf(str1, "%lc", (wint_t)122),
                   sprintf(str2, "%lc", (wint_t)122));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_spec_c_flags_test_3) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  ck_assert_int_eq(s21_sprintf(str1, "%1c", 'z'), sprintf(str2, "%1c", 'z'));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_spec_c_flags_test_4) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  ck_assert_int_eq(s21_sprintf(str1, "%1lc", (wint_t)122),
                   sprintf(str2, "%1lc", (wint_t)122));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_spec_c_flags_test_5) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  ck_assert_int_eq(s21_sprintf(str1, "%5c", 'z'), sprintf(str2, "%5c", 'z'));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_spec_c_flags_test_6) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  ck_assert_int_eq(s21_sprintf(str1, "%5lc", (wint_t)122),
                   sprintf(str2, "%5lc", (wint_t)122));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_test_9) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  ck_assert_int_eq(s21_sprintf(str1, "%-c", 'z'), sprintf(str2, "%-c", 'z'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_test_10) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  ck_assert_int_eq(s21_sprintf(str1, "%-lc", (wint_t)122),
                   sprintf(str2, "%-lc", (wint_t)122));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_test_11) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  ck_assert_int_eq(s21_sprintf(str1, "%-1c", 'z'), sprintf(str2, "%-1c", 'z'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_test_12) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  ck_assert_int_eq(s21_sprintf(str1, "%-1lc", (wint_t)122),
                   sprintf(str2, "%-1lc", (wint_t)122));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_spec_c_flags_test_13) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  ck_assert_int_eq(s21_sprintf(str1, "%-5c", 'z'), sprintf(str2, "%-5c", 'z'));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_spec_c_flags_test_14) {
  char str1[BUFF_SIZE] = "";
  char str2[BUFF_SIZE] = "";
  ck_assert_int_eq(s21_sprintf(str1, "%-5lc", (wint_t)122),
                   sprintf(str2, "%-5lc", (wint_t)122));
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *s21_sprintf_c_test(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_sprintf_c");

  tc = tcase_create("case_s21_sprintf_c");

  tcase_add_test(tc, sprintf_spec_c_default_test_1);
  tcase_add_test(tc, sprintf_spec_c_default_test_2);
  tcase_add_test(tc, sprintf_spec_c_default_test_3);
  tcase_add_test(tc, sprintf_spec_c_default_test_4);
  tcase_add_test(tc, sprintf_spec_c_flags_test_1);
  tcase_add_test(tc, sprintf_spec_c_flags_test_2);
  tcase_add_test(tc, sprintf_spec_c_flags_test_3);
  tcase_add_test(tc, sprintf_spec_c_flags_test_4);
  tcase_add_test(tc, sprintf_spec_c_flags_test_5);
  tcase_add_test(tc, sprintf_spec_c_flags_test_6);
  tcase_add_test(tc, sprintf_spec_c_flags_test_9);
  tcase_add_test(tc, sprintf_spec_c_flags_test_10);
  tcase_add_test(tc, sprintf_spec_c_flags_test_11);
  tcase_add_test(tc, sprintf_spec_c_flags_test_12);
  tcase_add_test(tc, sprintf_spec_c_flags_test_13);
  tcase_add_test(tc, sprintf_spec_c_flags_test_14);

  suite_add_tcase(s, tc);

  return s;
}