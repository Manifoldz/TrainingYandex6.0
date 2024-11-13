#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

char opposite(char a) {
  if (a == '(') {
    return ')';
  } else {
    return ']';
  }
}

int main(void) {
  int n{0};
  std::unordered_map<char, int> w;
  std::cin >> n;

  char temp = '\0';
  for (int i{0}; i < 4; ++i) {
    std::cin >> temp;
    w[temp] = i;
  }

  std::string s;
  std::cin >> s;
  std::cout << s;

  std::stack<char> st;
  int counter{0};
  for (size_t i{0}; i < s.size(); ++i) {
    if (s[i] == '(' || s[i] == '[') {
      st.push(s[i]);
    } else {
      st.pop();
      ++counter;
    }
  }
  counter += st.size();

  // std::cout << "\n stack: " << s << "\n";

  char inserted = '[';
  if (w['('] < w['[']) {
    inserted = '(';
  }

  while (counter != n / 2) {
    if (st.empty() || w[opposite(st.top())] > w[inserted]) {
      st.push(inserted);
      std::cout << inserted;
      ++counter;
    } else {
      std::cout << opposite(st.top());
      st.pop();
    }
  }

  while (!st.empty()) {
    std::cout << opposite(st.top());
    st.pop();
  }

  return 0;
}
