// Let's make C style :)
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int n;
  char** arr;
} Input_t;

typedef struct {
  char answer;
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
    // read n and prepare arr
    if (scanf("%d\n", &input->n) != 1) {
      *err = kErrInput;
    } else {
      input->n += 2;
      input->arr = (char**)SafeMalloc(
          sizeof(char) * input->n * input->n + sizeof(char) * input->n, err);
      if (*err == kOk) {
        char* ptr = (char*)(input->arr + input->n);
        for (int i = 0; i < input->n; i++) {
          input->arr[i] = ptr + i * input->n;
        }
      } else {
        return input;
      }
    }
    // read symbols
    for (int i = 0; i < input->n; i++) {
      for (int j = 0; j < input->n; j++) {
        if (i == 0 || j == 0 || i == input->n - 1) {
          input->arr[i][j] = '\'';
        } else if (j == input->n - 1) {
          input->arr[i][j] = '\'';
          getchar();
        } else {
          input->arr[i][j] = getchar();
        }
      }
    }
  }
  return input;
}

void PrintInput(Input_t* input) {
  printf("\n");
  for (int i = 0; i < input->n; i++) {
    for (int j = 0; j < input->n; j++) {
      printf("%c", input->arr[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void PrintOutput(const Output_t* output) { printf("%c\n", output->answer); }

Output_t* Process(Input_t* input, Error_t* err) {
  if (*err != kOk) {
    return NULL;
  }
  Output_t* output = (Output_t*)SafeMalloc(sizeof(Output_t), err);
  if (*err == kOk) {
    input->n = input->n;
  }

  return output;
}
