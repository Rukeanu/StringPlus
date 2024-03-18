#include "unit_tests.h"

START_TEST(empty_test) {
  s21_size_t n_byte = 0;
  char str[10] = "";
  int find_byte = '\0';

  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(zero_test) {
  s21_size_t n_byte = 7;
  char str[10] = "string";
  int find_byte = '\0';

  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(beginning_test) {
  s21_size_t n_byte = 6;
  char str[10] = "Atring";
  int find_byte = 'A';

  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(ending_test) {
  s21_size_t n_byte = 7;
  char str[10] = "StringA";
  int find_byte = 'A';

  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(middle_test) {
  s21_size_t n_byte = 15;
  char str[16] = "Str55333222ingA";
  int find_byte = '3';

  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(num_in_arr) {
  int array[] = {1, 2, 3, 666, 5, 99, 100};
  s21_size_t n_byte = sizeof(int) * 7;
  int find_byte = 666;

  ck_assert_ptr_eq(s21_memchr(array, find_byte, n_byte),
                   memchr(array, find_byte, n_byte));
}
END_TEST

Suite *s21_memchr_test(void) {
  Suite *s = suite_create("s21_memchr");
  TCase *tc = tcase_create("case_s21_memchr");
  tcase_add_test(tc, empty_test);
  tcase_add_test(tc, zero_test);
  tcase_add_test(tc, beginning_test);
  tcase_add_test(tc, ending_test);
  tcase_add_test(tc, middle_test);
  tcase_add_test(tc, num_in_arr);

  suite_add_tcase(s, tc);

  return s;
}