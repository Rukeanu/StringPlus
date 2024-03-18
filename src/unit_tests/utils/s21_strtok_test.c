#include "../unit_tests.h"

START_TEST(s21_strtok_1) {
  char str1[100] = "killer queen byte dust";
  char str2[100] = "er q";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(s21_strtok_2) {
  char str1[100] = "run boy run";
  char str2[100] = "12345";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(s21_strtok_3) {
  char str1[100] = "wonder of you %^&@@";
  char str2[100] = "%^@";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(s21_strtok_4) {
  char str1[100] = "go a go b go c go d";
  char str2[100] = "go";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(s21_strtok_5) {
  char str1[100] = "Rats are paris bithces which eat Paris's trash";
  char str2[100] = "";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(s21_strtok_6) {
  char str1[100] = "Rats are paris bithces which eat Paris's trash";
  char str2[100] = "w";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(s21_strtok_7) {
  char str1[100] = "hey yokgfjydjyd@!!!!!!!!!!!!!@@@#@@!!!";
  char str2[100] = "w";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(s21_strtok_8) {
  char str1[100] = "Rats are \0paris bithces which\0";
  char str2[100] = "a";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

Suite *s21_strtok_test(void) {
  Suite *s = suite_create("s21_strtok");
  TCase *tc = tcase_create("case_s21_strtok");

  tcase_add_test(tc, s21_strtok_1);
  tcase_add_test(tc, s21_strtok_2);
  tcase_add_test(tc, s21_strtok_3);
  tcase_add_test(tc, s21_strtok_4);
  tcase_add_test(tc, s21_strtok_5);
  tcase_add_test(tc, s21_strtok_6);
  tcase_add_test(tc, s21_strtok_7);
  tcase_add_test(tc, s21_strtok_8);

  suite_add_tcase(s, tc);
  return s;
}