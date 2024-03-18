#include "../unit_tests.h"

START_TEST(test_charVar) {
  const char input[] =
      "A 45552 0x2A 4.14 1.5e2 3.0 -42.5 +99.99 0755 Hello 42 0xFF 0XDEADBEEF "
      "0xDEADBEEF 12345\n";
  char charVar = '_';
  char s21_charVar = '_';

  sscanf(input, "%c", &charVar);
  s21_sscanf(input, "%c", &s21_charVar);

  ck_assert_int_eq(charVar, s21_charVar);
}
END_TEST

START_TEST(test_intVar1) {
  const char input[] =
      "A 45552 0x2A 4.14 1.5e2 3.0 -42.5 +99.99 0755 Hello 42 0xFF 0XDEADBEEF "
      "0xDEADBEEF 12345\n";
  int intVar1 = 0;
  int s21_intVar1 = 0;

  sscanf(input, "%d", &intVar1);
  s21_sscanf(input, "%d", &s21_intVar1);

  ck_assert_int_eq(intVar1, s21_intVar1);
}
END_TEST

START_TEST(test_doubleVar1) {
  const char input[] =
      "A 45552 0x2A 4.14 1.5e2 3.0 -42.5 +99.99 0755 Hello 42 0xFF 0XDEADBEEF "
      "0xDEADBEEF 12345\n";
  float doubleVar1 = 0.0;
  float s21_doubleVar1 = 0.0;

  sscanf(input, "%e", &doubleVar1);
  s21_sscanf(input, "%e", &s21_doubleVar1);

  ck_assert_double_eq_tol(doubleVar1, s21_doubleVar1, 0.0001);
}
END_TEST

START_TEST(test_exponentialVar_uppercase) {
  const char input[] =
      "A 45552 0x2A 4.14 1.5e2 3.0 -42.5 +99.99 0755 Hello 42 0xFF 0XDEADBEEF "
      "0xDEADBEEF 12345\n";
  float exponentialVar = 0.0;
  float s21_exponentialVar = 0.0;

  sscanf(input, "%E", &exponentialVar);
  s21_sscanf(input, "%E", &s21_exponentialVar);

  ck_assert_double_eq_tol(exponentialVar, s21_exponentialVar, 0.0001);
}
END_TEST

START_TEST(test_floatVar) {
  const char input[] =
      "A 45552 0x2A 4.14 1.5e2 3.0 -42.5 +99.99 0755 Hello 42 0xFF 0XDEADBEEF "
      "0xDEADBEEF 12345\n";
  float floatVar = 0.0f;
  float s21_floatVar = 0.0f;

  sscanf(input, "%f", &floatVar);
  s21_sscanf(input, "%f", &s21_floatVar);

  ck_assert_float_eq_tol(floatVar, s21_floatVar, 0.0001);
}
END_TEST

START_TEST(test_generalVar) {
  const char input[] =
      "A 45552 0x2A 4.14 1.5e2 3.0 -42.5 +99.99 0755 Hello 42 0xFF 0XDEADBEEF "
      "0xDEADBEEF 12345\n";
  float generalVar = 0.0f;
  float s21_generalVar = 0.0f;

  sscanf(input, "%g", &generalVar);
  s21_sscanf(input, "%g", &s21_generalVar);

  ck_assert_float_eq_tol(generalVar, s21_generalVar, 0.0001);
}
END_TEST

START_TEST(test_generalVar_uppercase) {
  const char input[] =
      "A 45552 0x2A 4.14 1.5e2 3.0 -42.5 +99.99 0755 Hello 42 0xFF 0XDEADBEEF "
      "0xDEADBEEF 12345\n";
  float generalVar = 0.0;
  float s21_generalVar = 0.0;

  sscanf(input, "%G", &generalVar);
  s21_sscanf(input, "%G", &s21_generalVar);

  ck_assert_double_eq_tol(generalVar, s21_generalVar, 0.0001);
}
END_TEST

START_TEST(test_octalVar) {
  const char input[] =
      "A 45552 0x2A 4.14 1.5e2 3.0 -42.5 +99.99 0755 Hello 42 0xFF 0XDEADBEEF "
      "0xDEADBEEF 12345\n";
  unsigned int octalVar = 0;
  unsigned int s21_octalVar = 0;

  sscanf(input, "%o", &octalVar);
  s21_sscanf(input, "%o", &s21_octalVar);

  ck_assert_int_eq(octalVar, s21_octalVar);
}
END_TEST

START_TEST(test_stringVar) {
  const char input[] =
      "A 45552 0x2A 4.14 1.5e2 3.0 -42.5 +99.99 0755 Hello 42 0xFF 0XDEADBEEF "
      "0xDEADBEEF 12345\n";
  char strVar[MAX_SI] = "";
  char s21_strVar[MAX_SI] = "";

  sscanf(input, "%255s", strVar);
  s21_sscanf(input, "%s", s21_strVar);

  ck_assert_str_eq(strVar, s21_strVar);
}
END_TEST

START_TEST(test_unsignedVar) {
  const char input[] =
      "A 45552 0x2A 4.14 1.5e2 3.0 -42.5 +99.99 0755 Hello 42 0xFF 0XDEADBEEF "
      "0xDEADBEEF 12345\n";
  unsigned int unsignedVar = 0;
  unsigned int s21_unsignedVar = 0;

  sscanf(input, "%u", &unsignedVar);
  s21_sscanf(input, "%u", &s21_unsignedVar);

  ck_assert_int_eq(unsignedVar, s21_unsignedVar);
}
END_TEST

START_TEST(test_hexVar_lowercase) {
  const char input[] =
      "A 45552 0x2A 4.14 1.5e2 3.0 -42.5 +99.99 0755 Hello 42 0xFF 0XDEADBEEF "
      "0xDEADBEEF 12345\n";
  unsigned int hexVar = 0;
  unsigned int s21_hexVar = 0;

  sscanf(input, "%x", &hexVar);
  s21_sscanf(input, "%x", &s21_hexVar);

  ck_assert_int_eq(hexVar, s21_hexVar);
}
END_TEST

START_TEST(test_hexVar_uppercase) {
  const char input[] =
      "A 45552 0x2A 4.14 1.5e2 3.0 -42.5 +99.99 0755 Hello 42 0xFF 0XDEADBEEF "
      "0xDEADBEEF 12345\n";
  unsigned int hexVar = 0;
  unsigned int s21_hexVar = 0;

  sscanf(input, "%X", &hexVar);
  s21_sscanf(input, "%X", &s21_hexVar);

  ck_assert_int_eq(hexVar, s21_hexVar);
}
END_TEST

START_TEST(test_pointerVar) {
  const char input[] =
      "A 45552 0x2A 4.14 1.5e2 3.0 -42.5 +99.99 0755 Hello 42 0xFF 0XDEADBEEF "
      "0xDEADBEEF 12345\n";
  void *pointerVar = NULL;
  void *s21_pointerVar = NULL;

  sscanf(input, "%p", &pointerVar);
  s21_sscanf(input, "%p", &s21_pointerVar);

  ck_assert_ptr_eq(pointerVar, s21_pointerVar);
}
END_TEST

START_TEST(test_numVar) {
  const char input[] =
      "A 45552 0x2A 4.14 1.5e2 3.0 -42.5 +99.99 0755 Hello 42 0xFF 0XDEADBEEF "
      "0xDEADBEEF 12345\n";
  int numVar = 0;
  int s21_numVar = 0;
  int numCharsRead = 0;
  int s21_numCharsRead = 0;

  sscanf(input, "%d%n", &numVar, &numCharsRead);
  s21_sscanf(input, "%d%n", &s21_numVar, &s21_numCharsRead);

  ck_assert_int_eq(numVar, s21_numVar);
  ck_assert_int_eq(numCharsRead, s21_numCharsRead);
}
END_TEST

START_TEST(test_width_and_sign) {
  const char input[] =
      "A 45552 0x2A 4.14 1.5e2 3.0 -42.5 +99.99 0755 Hello 42 0xFF 0XDEADBEE "
      "0xDEADBEEF 12345\n";
  int numVar = 0;
  float nuf = 0.0;
  float s21_nuf = 0.0;

  unsigned int nug = 0;
  unsigned int s21_nug = 0;

  int s21_numVar = 0;
  int numCharsRead = 0;
  int s21_numCharsRead = 0;

  sscanf(input, "%3d%n", &numVar, &numCharsRead);
  s21_sscanf(input, "%3d%n", &s21_numVar, &s21_numCharsRead);
  ck_assert_int_eq(numVar, s21_numVar);
  ck_assert_int_eq(numCharsRead, s21_numCharsRead);

  sscanf(input, "%4u%n", &nug, &numCharsRead);
  s21_sscanf(input, "%4u%n", &s21_nug, &s21_numCharsRead);
  ck_assert_int_eq(numVar, s21_numVar);
  ck_assert_int_eq(numCharsRead, s21_numCharsRead);

  sscanf(input, "%5f%n", &nuf, &numCharsRead);
  s21_sscanf(input, "%5f%n", &s21_nuf, &s21_numCharsRead);
  ck_assert_int_eq(nuf, s21_nuf);
  ck_assert_int_eq(numCharsRead, s21_numCharsRead);
}

END_TEST

START_TEST(test_width_star_d) {
  const char input[] =
      "A 45552 0x2A 4.14 1.5e2 3.0 -42.5 +99.99 0755 Hello 42 0xFF 0XDEADBEEF "
      "0xDEADBEEF 12345\n";

  int numCharsRead = 0;
  int s21_numCharsRead = 0;

  sscanf(input, "%*3d");
  s21_sscanf(input, "%*3d", &s21_numCharsRead);
  ck_assert_int_eq(numCharsRead, s21_numCharsRead);
}

START_TEST(test_width_star_x) {
  const char input[] =
      "A 45552 0x2A 4.14 1.5e2 3.0 -42.5 +99.99 0755 Hello 42 0xFF 0XDEADBEEF "
      "0xDEADBEEF 12345\n";

  int numCharsRead = 0;
  int s21_numCharsRead = 0;

  sscanf(input, "%*x");
  s21_sscanf(input, "%*x", &s21_numCharsRead);
  ck_assert_int_eq(numCharsRead, s21_numCharsRead);
}

START_TEST(test_width_star_f) {
  const char input[] =
      "A 45552 0x2A 4.14 1.5e2 3.0 -42.5 +99.99 0755 Hello 42 0xFF 0XDEADBEEF "
      "0xDEADBEEF 12345\n";

  int numCharsRead = 0;
  int s21_numCharsRead = 0;

  sscanf(input, "%*5f");
  s21_sscanf(input, "%*5f", &s21_numCharsRead);
  ck_assert_int_eq(numCharsRead, s21_numCharsRead);
}

START_TEST(test_width_star_s) {
  const char input[] =
      "A 45552 0x2A 4.14 1.5e2 3.0 -42.5 +99.99 0755 Hello 42 0xFF 0XDEADBEEF "
      "0xDEADBEEF 12345\n";

  int numCharsRead = 0;
  int s21_numCharsRead = 0;

  sscanf(input, "%*10s");
  s21_sscanf(input, "%*10s", &s21_numCharsRead);
  ck_assert_int_eq(numCharsRead, s21_numCharsRead);
}
END_TEST

START_TEST(test_short_specifier_hi) {
  short int shortValue = 0;
  sscanf("42", "%hi", &shortValue);
  short int s21_shortValue = 0;
  s21_sscanf("42", "%hi", &s21_shortValue);
  ck_assert_int_eq(shortValue, s21_shortValue);
}
END_TEST

START_TEST(test_short_specifier_hd) {
  short int numVar = 0;
  short int s21_numVar = 0;
  sscanf("42", "%hd", &numVar);
  s21_sscanf("42", "%hd", &s21_numVar);
  ck_assert_int_eq(numVar, s21_numVar);
}
END_TEST

START_TEST(test_short_specifier_ho) {
  unsigned short int ushortOctValue = 0;
  unsigned short int s21_ushortOctValue = 0;
  sscanf("5", "%ho", &ushortOctValue);
  s21_sscanf("5", "%ho", &s21_ushortOctValue);
  ck_assert_uint_eq(ushortOctValue, s21_ushortOctValue);
}
END_TEST

START_TEST(test_short_specifier_hu) {
  unsigned short int ushortValue = 0;
  unsigned short int s21_ushortValue = 0;
  sscanf("42", "%hu", &ushortValue);
  s21_sscanf("42", "%hu", &s21_ushortValue);
  ck_assert_uint_eq(ushortValue, s21_ushortValue);
}
END_TEST

START_TEST(test_long_specifier_li) {
  long int longValue = 0;
  sscanf("1234567890", "%li", &longValue);
  long int s21_longValue = 0;
  s21_sscanf("1234567890", "%li", &s21_longValue);
  ck_assert_int_eq(longValue, s21_longValue);
}
END_TEST

START_TEST(test_long_specifier_ld) {
  long int longDecValue = 0;
  sscanf("987654321", "%ld", &longDecValue);
  long int s21_longDecValue = 0;
  s21_sscanf("987654321", "%ld", &s21_longDecValue);
  ck_assert_int_eq(longDecValue, s21_longDecValue);
}
END_TEST

START_TEST(test_long_specifier_lu) {
  unsigned long int ulongValue = 0;
  sscanf("42", "%lu", &ulongValue);
  unsigned long int s21_ulongValue = 0;
  s21_sscanf("42", "%lu", &s21_ulongValue);
  ck_assert_uint_eq(ulongValue, s21_ulongValue);
}
END_TEST

START_TEST(test_long_specifier_lX) {
  unsigned long int ulongHexUpperValue = 0;
  sscanf("0", "%lX", &ulongHexUpperValue);
  unsigned long int s21_ulongHexUpperValue = 0;
  s21_sscanf("0", "%lX", &s21_ulongHexUpperValue);
  ck_assert_uint_eq(ulongHexUpperValue, s21_ulongHexUpperValue);
}
END_TEST

Suite *s21_sscanf_tests(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_sscanf");
  tc = tcase_create("case_s21_sscanf_tests");

  tcase_add_test(tc, test_charVar);
  tcase_add_test(tc, test_intVar1);
  tcase_add_test(tc, test_doubleVar1);
  tcase_add_test(tc, test_exponentialVar_uppercase);
  tcase_add_test(tc, test_floatVar);
  tcase_add_test(tc, test_generalVar);
  tcase_add_test(tc, test_generalVar_uppercase);
  tcase_add_test(tc, test_octalVar);
  tcase_add_test(tc, test_stringVar);
  tcase_add_test(tc, test_unsignedVar);
  tcase_add_test(tc, test_hexVar_lowercase);
  tcase_add_test(tc, test_hexVar_uppercase);
  tcase_add_test(tc, test_pointerVar);
  tcase_add_test(tc, test_numVar);
  tcase_add_test(tc, test_short_specifier_hi);
  tcase_add_test(tc, test_short_specifier_hd);
  tcase_add_test(tc, test_short_specifier_ho);
  tcase_add_test(tc, test_short_specifier_hu);
  tcase_add_test(tc, test_long_specifier_li);
  tcase_add_test(tc, test_long_specifier_ld);
  tcase_add_test(tc, test_long_specifier_lu);
  tcase_add_test(tc, test_long_specifier_lX);
  tcase_add_test(tc, test_width_and_sign);
  tcase_add_test(tc, test_width_star_d);
  tcase_add_test(tc, test_width_star_x);
  tcase_add_test(tc, test_width_star_f);
  tcase_add_test(tc, test_width_star_s);

  suite_add_tcase(s, tc);

  return s;
}