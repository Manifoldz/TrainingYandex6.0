#include <check.h>

#include "task2.c"

/*

Default

*/

START_TEST(ProcessDef) {
  int A = 6;
  int B = 2;
  int C = 7;
  int D = 3;

  Input_t input = {A, B, C, D};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_int_eq(output->pair[0], 3);
  ck_assert_int_eq(output->pair[1], 4);

  free(output);
}
END_TEST

/*

Usual

*/

START_TEST(ProcessUsual1) {
  int A = 1;
  int B = 100;
  int C = 100;
  int D = 2;

  Input_t input = {A, B, C, D};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_int_eq(output->pair[0] + output->pair[1], 102);

  free(output);
}
END_TEST

START_TEST(ProcessUsual2) {
  int A = 100;
  int B = 1;
  int C = 2;
  int D = 100;

  Input_t input = {A, B, C, D};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_int_eq(output->pair[0] + output->pair[1], 102);

  free(output);
}
END_TEST

START_TEST(ProcessUsual3) {
  int A = 100;
  int B = 2;
  int C = 1;
  int D = 100;

  Input_t input = {A, B, C, D};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_int_eq(output->pair[0] + output->pair[1], 102);

  free(output);
}
END_TEST

START_TEST(ProcessUsual4) {
  int A = 2;
  int B = 100;
  int C = 100;
  int D = 1;

  Input_t input = {A, B, C, D};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_int_eq(output->pair[0] + output->pair[1], 102);

  free(output);
}
END_TEST

START_TEST(ProcessUsual5) {
  int A = 3;
  int B = 2;
  int C = 2;
  int D = 4;

  Input_t input = {A, B, C, D};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_int_eq(output->pair[0], 4);
  ck_assert_int_eq(output->pair[1], 1);

  free(output);
}
END_TEST

/*

Equal

*/

START_TEST(ProcessEqual) {
  int A = 1;
  int B = 1;
  int C = 1;
  int D = 1;

  Input_t input = {A, B, C, D};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_int_eq(output->pair[0] + output->pair[1], 3);

  free(output);
}
END_TEST

/*

Zero

*/

START_TEST(ProcessZero1) {
  int A = 1;
  int B = 0;
  int C = 1;
  int D = 0;

  Input_t input = {A, B, C, D};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_int_eq(output->pair[0], 1);
  ck_assert_int_eq(output->pair[1], 1);

  free(output);
}
END_TEST

START_TEST(ProcessZero2) {
  int A = 1;
  int B = 0;
  int C = 1;
  int D = 1;

  Input_t input = {A, B, C, D};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_int_eq(output->pair[0], 1);
  ck_assert_int_eq(output->pair[1], 2);

  free(output);
}
END_TEST

START_TEST(ProcessZero3) {
  int A = 1;
  int B = 1;
  int C = 0;
  int D = 1;

  Input_t input = {A, B, C, D};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_int_eq(output->pair[0], 2);
  ck_assert_int_eq(output->pair[1], 1);

  free(output);
}
END_TEST

START_TEST(ProcessZero4) {
  int A = 0;
  int B = 2;
  int C = 3;
  int D = 4;

  Input_t input = {A, B, C, D};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_int_eq(output->pair[0], 1);
  ck_assert_int_eq(output->pair[1], 4);

  free(output);
}
END_TEST

START_TEST(ProcessZero5) {
  int A = 2;
  int B = 3;
  int C = 4;
  int D = 0;

  Input_t input = {A, B, C, D};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_int_eq(output->pair[0], 4);
  ck_assert_int_eq(output->pair[1], 1);

  free(output);
}
END_TEST

/*

Suites

*/

Suite *suite_process(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("process");
  tc_core = tcase_create("process - func");

  tcase_add_test(tc_core, ProcessDef);

  tcase_add_test(tc_core, ProcessUsual1);
  tcase_add_test(tc_core, ProcessUsual2);
  tcase_add_test(tc_core, ProcessUsual3);
  tcase_add_test(tc_core, ProcessUsual4);
  tcase_add_test(tc_core, ProcessUsual5);

  tcase_add_test(tc_core, ProcessEqual);

  tcase_add_test(tc_core, ProcessZero1);
  tcase_add_test(tc_core, ProcessZero2);
  tcase_add_test(tc_core, ProcessZero3);
  tcase_add_test(tc_core, ProcessZero4);
  tcase_add_test(tc_core, ProcessZero5);

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int nf = 0;
  Suite *s = suite_process();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  nf += srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
