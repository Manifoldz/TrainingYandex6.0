#include <iostream>
#include <stack>

int main(void) {
  std::stack<int> s;
  char temp_char = '\0';
  int temp_int;
  while (std::cin >> temp_char) {
    if (temp_char >= '0' && temp_char <= '9') {
      s.push(temp_char - '0');
    } else {
      temp_int = s.top();
      s.pop();
      if (temp_char == '+') {
        s.top() += temp_int;
      } else if (temp_char == '*') {
        s.top() *= temp_int;
      } else {
        s.top() -= temp_int;
      }
    }
  }
  std::cout << s.top();
  return 0;
}
