#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>

bool IsDigit(char c) { return c >= '0' && c <= '9'; }

#if 1
int Calculate(std::string& str) {
  str.push_back(' ');
  std::stack<int> s;
  int prev_top = 0;
  char prev_char = '0';
  int temp_int = 0;

  for (char curr_char : str) {
    if (IsDigit(curr_char)) {
      if (IsDigit(prev_char)) {
        temp_int = temp_int * 10 + (curr_char - '0');
      } else {
        temp_int = curr_char - '0';
      }
    } else {
      // push accumulated digits
      if (IsDigit(prev_char)) {
        s.push(temp_int);
      }
      if (curr_char != ' ') {
        prev_top = s.top();
        s.pop();
        if (s.empty()) {
          throw std::invalid_argument("don't have a second element in stack");
        }
        if (curr_char == '+') {
          s.top() += prev_top;
        } else if (curr_char == '*') {
          s.top() *= prev_top;
        } else if (curr_char == '-') {
          s.top() -= prev_top;
        } else {
          throw std::invalid_argument("wrong symbol in calculate");
        }
      }
    }
    prev_char = curr_char;
  }

  if (s.size() != 1 || str.size() == 1) {
    throw std::invalid_argument("not enough operators");
  }

  return s.top();
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

void AddSpace(std::string& str) {
  if (!str.empty() && str.back() != ' ') {
    str += ' ';
  }
}

void AddOperator(std::string& str, std::stack<char>& s) {
  AddSpace(str);
  str += s.top();
  s.pop();
}

std::string Parse() {
  std::stack<char> s;
  std::string parsed_str;
  char prev_char = '\0', curr_char = std::cin.get();

  while (curr_char != '\n') {
    if (curr_char == ' ') {
      AddSpace(parsed_str);
    } else if (IsDigit(curr_char)) {
      parsed_str += curr_char;
    } else if (curr_char == '(') {
      s.push(curr_char);
    } else if (curr_char == ')') {
      while (!s.empty() && s.top() != '(') {
        AddOperator(parsed_str, s);
      }
      if (s.empty()) {
        throw std::invalid_argument("no finded '('");
      } else {
        s.pop();
      }
    } else if (curr_char == '+' || curr_char == '*' || curr_char == '-') {
      AddSpace(parsed_str);
      // hack to fix unar minus
      if (curr_char == '-' && !IsDigit(prev_char)) {
        parsed_str += "0 ";
      } else if (!IsDigit(prev_char)) {
        throw std::invalid_argument("several operators one by one");
      }
      while (!s.empty() && Priority(curr_char) <= Priority(s.top())) {
        AddOperator(parsed_str, s);
      }
      s.push(curr_char);
    } else {
      throw std::invalid_argument("wrong symbol");
    }

    if (curr_char != ' ') {
      prev_char = curr_char;
    }
    curr_char = std::cin.get();
  }

  while (!s.empty()) {
    AddOperator(parsed_str, s);
  }

  return parsed_str;
}

int main(void) {
  try {
    std::string parsed_str = Parse();
    // std::cout << parsed_str;
    std::cout << Calculate(parsed_str);
  } catch (std::invalid_argument) {
    std::cout << "WRONG";
  }
  return 0;
}
