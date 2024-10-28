#include <check.h>

#include "task3.c"

/*

Default

*/

START_TEST(ProcessDef1) {
  char row0[] = "''''''''";
  char row1[] = "'#####.'";
  char row2[] = "'##..#.'";
  char row3[] = "'##..#.'";
  char row4[] = "'#####.'";
  char row5[] = "'##....'";
  char row6[] = "'##....'";
  char row7[] = "''''''''";

  char *diods[] = {row0, row1, row2, row3, row4, row5, row6, row7};
  Input_t input = {8, diods};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_int_eq(output->answer, 'P');

  free(output);
}
END_TEST

START_TEST(ProcessDef2) {
  char row0[] = "''''''''";
  char row1[] = "'.##.'";
  char row2[] = "'.##.'";
  char row3[] = "'.##.'";
  char row4[] = "'....'";
  char row5[] = "''''''''";

  char *diods[] = {row0, row1, row2, row3, row4, row5};
  Input_t input = {6, diods};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_int_eq(output->answer, 'I');

  free(output);
}
END_TEST

START_TEST(ProcessDef3) {
  char row0[] = "''''''''";
  char row1[] = "'#...#'";
  char row2[] = "'.#.#.'";
  char row3[] = "'..#..'";
  char row4[] = "'.#.#.'";
  char row5[] = "'#...#'";
  char row6[] = "''''''''";

  char *diods[] = {row0, row1, row2, row3, row4, row5, row6};
  Input_t input = {7, diods};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_int_eq(output->answer, 'X');

  free(output);
}
END_TEST

START_TEST(ProcessDef4) {
  char row0[] = "''''''''";
  char row1[] = "'####'";
  char row2[] = "'##..'";
  char row3[] = "'##..'";
  char row4[] = "'####'";
  char row5[] = "''''''''";

  char *diods[] = {row0, row1, row2, row3, row4, row5};
  Input_t input = {6, diods};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_int_eq(output->answer, 'C');

  free(output);
}
END_TEST

START_TEST(ProcessDef5) {
  char row0[] = "''''''''";
  char row1[] = "'##....#'";
  char row2[] = "'##....#'";
  char row3[] = "'##....#'";
  char row4[] = "'#######'";
  char row5[] = "'##....#'";
  char row6[] = "'##....#'";
  char row7[] = "'##....#'";
  char row8[] = "''''''''";

  char *diods[] = {row0, row1, row2, row3, row4, row5, row6, row7, row8};
  Input_t input = {9, diods};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_int_eq(output->answer, 'H');

  free(output);
}
END_TEST

/*

Usual

*/

START_TEST(ProcessUsual1) {
  char row0[] = "''''''''";
  char row1[] = "'.####..'";
  char row2[] = "'.##....'";
  char row3[] = "'.##....'";
  char row4[] = "'.####..'";
  char row5[] = "'......'";
  char row6[] = "'......'";
  char row7[] = "''''''''";

  char *diods[] = {row0, row1, row2, row3, row4, row5, row6, row7};
  Input_t input = {8, diods};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_int_eq(output->answer, 'C');

  free(output);
}
END_TEST

/*

Wrong

*/

START_TEST(ProcessWrong1) {
  char row0[] = "''''''''";
  char row1[] = "'#####.'";
  char row2[] = "'##..#.'";
  char row3[] = "'##..#.'";
  char row4[] = "'#####.'";
  char row5[] = "'##....'";
  char row6[] = "'##..#.'";
  char row7[] = "''''''''";

  char *diods[] = {row0, row1, row2, row3, row4, row5, row6, row7};
  Input_t input = {8, diods};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_int_eq(output->answer, 'X');

  free(output);
}
END_TEST

START_TEST(ProcessWrong2) {
  char row0[] = "''''''''";
  char row1[] = "'.####..'";
  char row2[] = "'.##....'";
  char row3[] = "'.##....'";
  char row4[] = "'.####..'";
  char row5[] = "'......'";
  char row6[] = "'....#.'";
  char row7[] = "''''''''";

  char *diods[] = {row0, row1, row2, row3, row4, row5, row6, row7};
  Input_t input = {8, diods};
  Error_t err = kOk;
  Output_t *output = Process(&input, &err);

  ck_assert_int_eq(err, kOk);
  ck_assert_int_eq(output->answer, 'X');

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

  tcase_add_test(tc_core, ProcessDef1);
  tcase_add_test(tc_core, ProcessDef2);
  tcase_add_test(tc_core, ProcessDef3);
  tcase_add_test(tc_core, ProcessDef4);
  tcase_add_test(tc_core, ProcessDef5);

  tcase_add_test(tc_core, ProcessUsual1);

  tcase_add_test(tc_core, ProcessWrong1);
  tcase_add_test(tc_core, ProcessWrong2);

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
