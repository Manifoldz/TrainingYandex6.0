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

void Swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int Min(int a, int b) { return a < b ? a : b; }

Output_t* Process(Input_t* input, Error_t* err) {
  if (*err != kOk) {
    return NULL;
  }
  Output_t* output = (Output_t*)SafeMalloc(sizeof(Output_t), err);
  if (*err != kOk) {
    return NULL;
  }
  output->answer = 'X';
  // Search light diods
  Rect_t light_rect = {0, 0, 1, 1};
  for (int i = 1; i < input->n - 1; i++) {
    for (int j = 1; j < input->n - 1; j++) {
      if (input->arr[i][j] == '#') {
        if (light_rect.x == 0) {
          light_rect.y = i;
          light_rect.x = j;
        } else if (j < light_rect.x) {
          light_rect.x = j;
        } else if (light_rect.x + light_rect.width <= j) {
          ++light_rect.width;
        } else if (light_rect.y + light_rect.height <= i) {
          ++light_rect.height;
        }
      }
    }
  }
  if (light_rect.x == 0) {
    return output;
  }
  const int x1 = light_rect.x;
  const int y1 = light_rect.y + light_rect.height - 1;
  const int x2 = light_rect.x + light_rect.width - 1;
  const int y2 = light_rect.y;
  // Mark rectangles
  Rect_t rect[2] = {{0}, {0}};
  int count_rect = 0;
  for (int i = y2; i <= y1; i++) {
    for (int j = x1; j <= x2; j++) {
      if (input->arr[i][j] == '.') {
        if (count_rect == 2) {
          return output;
        }
        rect[count_rect].y = i;
        rect[count_rect].x = j;
        rect[count_rect].width = CountWidth(input, i, j);
        if (rect[count_rect].width + rect[count_rect].x > x2) {
          rect[count_rect].width = x2 - rect[count_rect].x + 1;
        }
        MarkWidth(input, i, j, rect[count_rect].width, count_rect);
        while (CountWidth(input, i + rect[count_rect].height + 1, j) >=
                   rect[count_rect].width &&
               rect[count_rect].y + rect[count_rect].height < y1) {
          ++rect[count_rect].height;
          MarkWidth(input, i + rect[count_rect].height, j,
                    rect[count_rect].width, count_rect);
        }
        ++rect[count_rect].height;
        ++count_rect;
      }
    }
  }
  // Analys
  if (count_rect == 0) {
    output->answer = 'I';
    return output;
  }

  int x3 = rect[0].x;
  int y3 = rect[0].y + rect[0].height - 1;
  int x4 = rect[0].x + rect[0].width - 1;
  int y4 = rect[0].y;

  // PrintInput(input);

  if (count_rect == 1) {
    if (y1 > y3 && y3 >= y4 && y4 > y2) {
      // printf("yes");
      if (x1 < x3 && x3 <= x4) {
        if (x4 < x2) {
          output->answer = 'O';
        } else if (x4 == x2) {
          output->answer = 'C';
        }
      }
    } else if (y1 > y3 && y3 >= y4 && y4 == y2) {
      // printf("yes");
      if (x1 < x3 && x3 <= x4 && x4 == x2) {
        output->answer = 'L';
      }
    }
    return output;
  }

  if (count_rect == 2) {
    int x5 = rect[1].x;
    int y5 = rect[1].y + rect[1].height - 1;
    int x6 = rect[1].x + rect[1].width - 1;
    int y6 = rect[1].y;
    if (y6 > y4) {
      Swap(&x5, &x3);
      Swap(&y5, &y3);
      Swap(&x6, &x4);
      Swap(&y6, &y4);
    }
    if (x1 < x3 && x3 == x5 && x5 <= x4 && x4 == x6 && x6 < x2) {
      if (y1 == y3 && y3 >= y4 && y4 > y5 && y5 >= y6 && y6 == y2) {
        output->answer = 'H';
      }
    } else if (x1 < x3 && x3 == x5 && x5 <= x6 && x6 < x4 && x4 == x2) {
      if (y1 == y3 && y3 >= y4 && y4 > y5 && y5 >= y6 && y6 > y2) {
        output->answer = 'P';
      }
    }
  }

  return output;
}
