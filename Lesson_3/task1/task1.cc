#include <iostream>
#include <stack>

int main(void) {
  char ch = '\0';
  std::stack<char> s;
  bool res = true;
  while (std::cin >> ch && res) {
    if (ch == '(' || ch == '[' || ch == '{') {
      s.push(ch);
    } else if (ch == ')') {
      if (!s.empty() && s.top() == '(') {
        s.pop();
      } else {
        res = false;
      }
    } else if (!s.empty() && (ch == ']' || ch == '}')) {
      if (s.top() == ch - 2) {
        s.pop();
      } else {
        res = false;
      }
    } else {
      res = false;
    }
  }
  if (!s.empty()) {
    res = false;
  }
  std::cout << ((res) ? "yes" : "no");
  return 0;
}
