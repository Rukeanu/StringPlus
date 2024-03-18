#include "../unit_tests.h"

START_TEST(errors) {
  for (int i = 0; i < 107; i++) {
    char *def = s21_strerror(i);
    char *expect = strerror(i);
    ck_assert_str_eq(def, expect);
  }
}
END_TEST

START_TEST(negativ) {
  char *expect = strerror(-1);
  char *def = s21_strerror(-1);
  ck_assert_str_eq(def, expect);
}
END_TEST

Suite *s21_strerror_test(void) {
  Suite *s = suite_create("s21_strerror");
  TCase *tc = tcase_create("case_s21_strerror");

  tcase_add_test(tc, errors);
  tcase_add_test(tc, negativ);

  suite_add_tcase(s, tc);

  return s;
}