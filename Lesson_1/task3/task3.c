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

typedef struct {
  int x;
  int y;
  int width;
  int height;
} Rect_t;

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
          sizeof(char) * input->n * input->n + sizeof(char*) * input->n, err);
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

void MarkWidth(Input_t* input, int i, int j, int width, int count_rect) {
  for (int k = 0; k < width; k++) {
    input->arr[i][j + k] = '1' + count_rect;
  }
}

int CountWidth(Input_t* input, int i, int j) {
  int counter = 0;
  while (input->arr[i][j + counter] == '.') {
    ++counter;
  }
  return counter;
}

Output_t* Process(Input_t* input, Error_t* err) {
  if (*err != kOk) {
    return NULL;
  }
  Output_t* output = (Output_t*)SafeMalloc(sizeof(Output_t), err);
  if (*err == kOk) {
    int count_rect = 0;
    output->answer = 'X';
    Rect_t light_rect = {0, 0, 1, 1};
    // Search light diods
    for (int i = 1; i < input->n - 1; i++) {
      for (int j = 1; j < input->n - 1; j++) {
        if (input->arr[i][j] == '#') {
          if (light_rect.x == 0) {
            light_rect.y = i;
            light_rect.x = j;
          } else if (light_rect.x + light_rect.width <= j) {
            ++light_rect.width;
          } else if (light_rect.y + light_rect.height <= i) {
            ++light_rect.height;
          }
        }
      }
    }
    printf("\n%d %d\n", light_rect.y, light_rect.x);
    printf("\n%d %d\n", light_rect.width, light_rect.height);
    Rect_t rect[2] = {{0}, {0}};
    // Mark rectangles
    for (int i = light_rect.y; i < light_rect.y + light_rect.height; i++) {
      for (int j = light_rect.x; j < light_rect.x + light_rect.width; j++) {
        if (input->arr[i][j] == '.') {
          if (count_rect == 2) {
            return output;
          }
          rect[count_rect].y = i;
          rect[count_rect].x = j;
          rect[count_rect].width = CountWidth(input, i, j);
          MarkWidth(input, i, j, rect[count_rect].width, count_rect);
          while (CountWidth(input, i + rect[count_rect].height + 1, j) >=
                     rect[count_rect].width &&
                 rect[count_rect].y + rect[count_rect].height + 1 <
                     light_rect.y + light_rect.height) {
            ++rect[count_rect].height;
            MarkWidth(input, i + rect[count_rect].height, j,
                      rect[count_rect].width, count_rect);
          }
          ++count_rect;
        }
      }
    }
  }
  return output;
}
