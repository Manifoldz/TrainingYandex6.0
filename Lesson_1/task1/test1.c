#include <check.h>

#include "task1.c"

/*

Default

*/

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
  ck_assert_str_eq(output->answer, "NW");

  free(output);
}
END_TEST

/*

Usual

*/

START_TEST(ProcessN) {
  int x1 = 10;
  int y1 = 30;
  int x2 = 20;
  int y2 = 40;
  int x = 15;
  int y = 41;

  Input_t input = {x1, y1, x2, y2, x, y};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_str_eq(output->answer, "N");

  free(output);
}
END_TEST

START_TEST(ProcessS) {
  int x1 = 10;
  int y1 = 30;
  int x2 = 20;
  int y2 = 40;
  int x = 15;
  int y = 29;

  Input_t input = {x1, y1, x2, y2, x, y};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_str_eq(output->answer, "S");

  free(output);
}
END_TEST

START_TEST(ProcessW) {
  int x1 = 10;
  int y1 = 30;
  int x2 = 20;
  int y2 = 40;
  int x = 9;
  int y = 35;

  Input_t input = {x1, y1, x2, y2, x, y};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_str_eq(output->answer, "W");

  free(output);
}
END_TEST

START_TEST(ProcessE) {
  int x1 = 10;
  int y1 = 30;
  int x2 = 20;
  int y2 = 40;
  int x = 21;
  int y = 35;

  Input_t input = {x1, y1, x2, y2, x, y};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_str_eq(output->answer, "E");

  free(output);
}
END_TEST

START_TEST(ProcessNE) {
  int x1 = 10;
  int y1 = 30;
  int x2 = 20;
  int y2 = 40;
  int x = 21;
  int y = 41;

  Input_t input = {x1, y1, x2, y2, x, y};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_str_eq(output->answer, "NE");

  free(output);
}
END_TEST

START_TEST(ProcessSE) {
  int x1 = 10;
  int y1 = 30;
  int x2 = 20;
  int y2 = 40;
  int x = 21;
  int y = 29;

  Input_t input = {x1, y1, x2, y2, x, y};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_str_eq(output->answer, "SE");

  free(output);
}
END_TEST

START_TEST(ProcessSW) {
  int x1 = 10;
  int y1 = 30;
  int x2 = 20;
  int y2 = 40;
  int x = 9;
  int y = 29;

  Input_t input = {x1, y1, x2, y2, x, y};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_str_eq(output->answer, "SW");

  free(output);
}
END_TEST

START_TEST(ProcessNW) {
  int x1 = 10;
  int y1 = 30;
  int x2 = 20;
  int y2 = 40;
  int x = 9;
  int y = 41;

  Input_t input = {x1, y1, x2, y2, x, y};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_str_eq(output->answer, "NW");

  free(output);
}
END_TEST

/*

Negative

*/

START_TEST(ProcessNegativeN) {
  int x1 = -20;
  int y1 = 30;
  int x2 = -10;
  int y2 = 40;
  int x = -15;
  int y = 41;

  Input_t input = {x1, y1, x2, y2, x, y};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_str_eq(output->answer, "N");

  free(output);
}
END_TEST

START_TEST(ProcessNegativeW) {
  int x1 = -20;
  int y1 = -40;
  int x2 = -10;
  int y2 = -30;
  int x = -30;
  int y = -35;

  Input_t input = {x1, y1, x2, y2, x, y};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_str_eq(output->answer, "W");

  free(output);
}
END_TEST

START_TEST(ProcessNegativeSW) {
  int x1 = -20;
  int y1 = -40;
  int x2 = -10;
  int y2 = -30;
  int x = -30;
  int y = -41;

  Input_t input = {x1, y1, x2, y2, x, y};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_str_eq(output->answer, "SW");

  free(output);
}
END_TEST

/*

Zero

*/

START_TEST(ProcessZeroE) {
  int x1 = 0;
  int y1 = 30;
  int x2 = 2;
  int y2 = 40;
  int x = 1;
  int y = -20;

  Input_t input = {x1, y1, x2, y2, x, y};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_str_eq(output->answer, "S");

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
  tc_core = tcase_create("process-func");

  tcase_add_test(tc_core, ProcessDef);
  tcase_add_test(tc_core, ProcessN);
  tcase_add_test(tc_core, ProcessS);
  tcase_add_test(tc_core, ProcessW);
  tcase_add_test(tc_core, ProcessE);
  tcase_add_test(tc_core, ProcessNE);
  tcase_add_test(tc_core, ProcessSE);
  tcase_add_test(tc_core, ProcessSW);
  tcase_add_test(tc_core, ProcessNW);

  tcase_add_test(tc_core, ProcessNegativeN);
  tcase_add_test(tc_core, ProcessNegativeW);
  tcase_add_test(tc_core, ProcessNegativeSW);

  tcase_add_test(tc_core, ProcessZeroE);

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
