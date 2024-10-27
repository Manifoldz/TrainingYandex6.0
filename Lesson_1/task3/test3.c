#include <check.h>

#include "task3.c"

/*

Default

*/

START_TEST(ProcessDef1) {
  int A = 6;
  int B = 2;
  int C = 7;
  int D = 3;

  Input_t input = {A, B, C, D};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);

  free(output);
}
END_TEST

/*

Usual

*/

/*

Negative

*/

/*

Zero

*/

/*

Suites

*/

Suite *suite_process(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("process");
  tc_core = tcase_create("process-func");

  tcase_add_test(tc_core, ProcessDef1);

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
