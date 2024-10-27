#include "task1.c"

int main(void) {
  Error_t err = kOk;
  Input_t* input = ReadInput(&err);
  if (err == kOk) {
    Output_t* output = Process(input, &err);
    if (err == kOk) {
      PrintOutput(output);
    }
    free(input);
  }
  return err;
}