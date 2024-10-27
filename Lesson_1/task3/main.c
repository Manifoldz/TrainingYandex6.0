#include "task3.c"
#if 1
int main(void) {
  Error_t err = kOk;
  Input_t* input = ReadInput(&err);
  if (err == kOk) {
    Output_t* output = Process(input, &err);
    if (err == kOk) {
      PrintOutput(output);
    }
    free(output);
  }
  free(input);
  return err;
}
#endif
#if 0
int main(void) {
  Error_t err = kOk;
  Input_t* input = ReadInput(&err);
  if (err == kOk) {
    PrintInput(input);
  }
  free(input);
  return err;
}
#endif