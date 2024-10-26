#include <check.h>

#include "task1.c"

START_TEST(ProcessDef) {
  int x1 = -1;
  int y1 = -2;
  int x2 = 5;
  int y2 = 3;
  int x = -4;
  int y = 6;

  Input_t input = {x1, y1, x2, y2, x, y};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_str_eq(output->answer, "NE");

  free(output);
}
END_TEST

Suite *suite_process(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("process");
  tc_core = tcase_create("process-func");
  tcase_add_test(tc_core, ProcessDef);
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
