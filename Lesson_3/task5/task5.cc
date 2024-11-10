#include <iostream>
#include <stack>

bool IsDigit(char c) { return c >= '0' && c <= '9'; }

#if 0
int Calculate(std::string &str) {
  std::stack<int> s;
  int prev_top = 0;
  char prev_char = '0';
  int temp_int = 0;

  for (char curr_char : str) {
    if (IsDigit(curr_char)) {
      if (IsDigit(prev_char)) {
        temp_int = temp_int * 10 + (prev_char - '0');
      } else {
        temp_int = prev_char - '0';
      }
      prev_char = curr_char;
    } else {
      // push accumulated digits
      if (IsDigit(prev_char)) {
        s.push(temp_int);
      }
      prev_top = s.top();
      s.pop();
      if (curr_char == '+') {
        s.top() += prev_top;
      } else if (curr_char == '*') {
        s.top() *= prev_top;
      } else if (curr_char == '-') {
        if (IsDigit(prev_char)) {
          s.top() -= prev_top;
        } else
      }
    }
  }

  return temp_int;
}
#endif

int Priority(char c) {
  int res = 0;
  if (c == '+' || c == '-') {
    res = 1;
  } else if (c == '*') {
    res = 2;
  }
  return res;
}

int main(void) {
  char curr_char = '\0';
  char prev_char = '\0';

  std::cin >> curr_char;

  std::string parsed_str;
  std::stack<char> s;

  while (curr_char != '\n') {
    std::cout << curr_char << "_";
    if (IsDigit(curr_char) || curr_char == ' ') {
      parsed_str += curr_char;
    } else if (curr_char == '(') {
      s.push(curr_char);
    } else if (curr_char == ')') {
      while (!s.empty() && s.top() != '(') {
        parsed_str += s.top();
        s.pop();
      }
      if (s.empty()) {
        // in case no finded '('
        std::cout << "WRONG";
        return 0;
      } else {
        s.pop();
      }
    } else if (curr_char == '+' || curr_char == '*' ||
               (curr_char == '-' && IsDigit(prev_char))) {
      while (!s.empty() && Priority(curr_char) >= Priority(s.top())) {
        parsed_str += s.top();
        s.pop();
      }
      s.push(curr_char);
    } else if (curr_char == '-') {
      // hack - use '!' for highlight unar '-'
      parsed_str += '!';
    } else {
      // in case other symbols
      std::cout << "WRONG";
      return 0;
    }

    if (curr_char != ' ') {
      prev_char = curr_char;
    }
    std::cin >> curr_char;
  }

  while (!s.empty()) {
    parsed_str += s.top();
  }

  std::cout << parsed_str;

  // int res = 0;
  //   if (Calculate(parsed_str, &res)) {
  //     std::cout << "WRONG";
  //   } else {
  //     std::cout << res;
  //   }

  return 0;
}
