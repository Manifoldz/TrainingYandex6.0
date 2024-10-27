// Let's make C style :)
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int A;
  int B;
  int C;
  int D;
} Input_t;

typedef struct {
  int M;
  int N;
} Output_t;

typedef enum {
  kOk = 0,
  kErrInput = 1,
  kErrProcess = 2,
  kErrAlloc = 4,
  kErrInternal = 5
} Error_t;

void* SafeMalloc(size_t size, Error_t* err) {
  void* ptr = NULL;
  if (*err == kOk) {
    if (size > 0) {
      ptr = malloc(size);
      if (ptr == NULL) {
        *err = kErrAlloc;
      }
    } else {
      *err = kErrInternal;
    }
  }
  return ptr;
}

Input_t* ReadInput(Error_t* err) {
  if (*err != kOk) {
    return NULL;
  }
  Input_t* input = (Input_t*)SafeMalloc(sizeof(Input_t), err);
  if (*err == kOk) {
    if (scanf("%d%d%d%d", &input->A, &input->B, &input->C, &input->D) != 4) {
      free(input);
      *err = kErrInput;
    };
  }
  return input;
}

void PrintOutput(const Output_t* output) {
  printf("%d %d\n", output->M, output->N);
}

Output_t* Process(Input_t* input, Error_t* err) {
  if (*err != kOk) {
    return NULL;
  }
  Output_t* output = (Output_t*)SafeMalloc(sizeof(Output_t), err);

  return output;
}