// Let's make C style :)
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x1;
  int y1;
  int x2;
  int y2;
  int x;
  int y;
} Input_t;

typedef struct {
  const char* answer;
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
    if (scanf("%d%d%d%d%d%d", &input->x1, &input->y1, &input->x2, &input->y2,
              &input->x, &input->y) != 6) {
      free(input);
      *err = kErrInput;
    };
  }
  return input;
}

void PrintOutput(const Output_t* output) { printf("%s\n", output->answer); }

Output_t* Process(Input_t* input, Error_t* err) {
  if (*err != kOk) {
    return NULL;
  }
  Output_t* output = (Output_t*)SafeMalloc(sizeof(Output_t), err);
  if (*err == kOk) {
    if (input->x > input->x1 && input->x < input->x2) {
      output->answer = (input->y > input->y1) ? "N" : "S";
    } else if (input->y > input->y1 && input->y < input->y2) {
      output->answer = (input->x > input->x1) ? "E" : "W";
    } else {
      if (input->x > input->x1) {
        output->answer = (input->y > input->y1) ? "NE" : "SE";
      } else {
        output->answer = (input->y > input->y1) ? "NW" : "SW";
      }
    }
    // if (*err != kOk) {
    //   free(output);
    // }
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
    free(input);
  }
  return 0;
}
