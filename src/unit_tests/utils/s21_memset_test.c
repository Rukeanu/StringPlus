#include "../unit_tests.h"

START_TEST(abrakadabra_test) {
  char def[] = "abrakadabra";
  char expect[] = "abrakadabra";
  char repl = 'i';
  s21_size_t num_byte = 11;

  s21_memset(def, repl, num_byte);
  memset(expect, repl, num_byte);

  ck_assert_str_eq(def, expect);
}
END_TEST

START_TEST(empty_test) {
  char def[] = "";
  char expect[] = "";
  char repl = '\0';
  s21_size_t num_byte = 0;

  s21_memset(def, repl, num_byte);
  memset(expect, repl, num_byte);

  ck_assert_str_eq(def, expect);
}
END_TEST

START_TEST(zero_test) {
  char def[] = "abrakadabra";
  char expect[] = "abrakadabra";
  char repl = 'i';
  s21_size_t num_byte = 0;

  s21_memset(def, repl, num_byte);
  memset(expect, repl, num_byte);

  ck_assert_str_eq(def, expect);
}
END_TEST

START_TEST(uppercase_test) {
  char def[] = "abrakadabra";
  char expect[] = "abrakadabra";
  char repl = 'I';
  s21_size_t num_byte = 5;

  s21_memset(def, repl, num_byte);
  memset(expect, repl, num_byte);

  ck_assert_str_eq(def, expect);
}
END_TEST

START_TEST(num_test) {
  char def[] = "abr4kadabra";
  char expect[] = "abr4kadabra";
  char repl = '4';
  s21_size_t num_byte = 11;

  s21_memset(def, repl, num_byte);
  memset(expect, repl, num_byte);

  ck_assert_str_eq(def, expect);
}
END_TEST

Suite *s21_memset_test(void) {
  Suite *s = suite_create("s21_memset");
  TCase *tc = tcase_create("case_s21_memset");
  tcase_add_test(tc, abrakadabra_test);
  tcase_add_test(tc, empty_test);
  tcase_add_test(tc, zero_test);
  tcase_add_test(tc, uppercase_test);
  tcase_add_test(tc, num_test);
  suite_add_tcase(s, tc);

  return s;
}