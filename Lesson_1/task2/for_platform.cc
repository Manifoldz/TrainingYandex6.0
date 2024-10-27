// Let's make C style :)
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int b1;
  int r1;
  int b2;
  int r2;
} Input_t;

typedef struct {
  int pair[2];
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
    if (scanf("%d%d%d%d", &input->b1, &input->r1, &input->b2, &input->r2) !=
        4) {
      *err = kErrInput;
    };
  }
  return input;
}

void PrintOutput(const Output_t* output) {
  printf("%d %d\n", output->pair[0], output->pair[1]);
}

int Min(int a, int b) { return a < b ? a : b; }
int Max(int a, int b) { return a < b ? b : a; }

Output_t* Process(Input_t* input, Error_t* err) {
  if (*err != kOk) {
    return NULL;
  }
  Output_t* output = (Output_t*)SafeMalloc(sizeof(Output_t), err);

  if (*err == kOk) {
    int matrix[2][2] = {{input->b1, input->r1}, {input->b2, input->r2}};
    output->pair[0] = 1;
    output->pair[1] = 1;

    // zero process
    int stop = 0;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        if (matrix[i][j] == 0) {
          output->pair[1 - i] = matrix[1 - i][j] + 1;
          stop = 1;
        }
      }
    }
    if (stop) {
      return output;
    }
    // usual cases
    int max1 = Max(matrix[0][0], matrix[0][1]);
    int max2 = Max(matrix[1][0], matrix[1][1]);
    if (max1 < max2) {
      output->pair[0] = max1 + 1;
    } else {
      output->pair[1] = max2 + 1;
    }
    if (matrix[0][0] + matrix[1][0] + 2 < output->pair[0] + output->pair[1]) {
      output->pair[0] = matrix[0][0] + 1;
      output->pair[1] = matrix[1][0] + 1;
    }
    if (matrix[0][1] + matrix[1][1] + 2 < output->pair[0] + output->pair[1]) {
      output->pair[0] = matrix[0][1] + 1;
      output->pair[1] = matrix[1][1] + 1;
    }
  }

  return output;
}

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
