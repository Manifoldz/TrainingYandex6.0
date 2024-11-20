#include <iostream>
#include <map>
#include <string>
#include <unordered_set>

std::string &find_common(std::map<std::string, std::string> &m,
                         std::string &left, std::string &right) {
  std::unordered_set<std::string> s;
  s.insert(left);
  while (m[left] != "") {
    s.insert(m[left]);
    left = m[left];
  }

  if (s.find(right) != s.end()) {
    return right;
  }

  while (s.find(m[right]) == s.end()) {
    right = m[right];
  }

  return m[right];
}

int main(void) {
  int n = 0;
  std::cin >> n;

  std::map<std::string, std::string> m;

  std::string name, parent;
  for (int i = 0; i < n - 1; ++i) {
    std::cin >> name >> parent;
    m[name] = parent;
    m[parent];
  }

  std::string left, right;
  while (std::cin >> left >> right) {
    std::cout << find_common(m, left, right) << "\n";
  }

  return 0;
}