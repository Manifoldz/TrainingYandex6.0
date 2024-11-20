#include <iostream>
#include <map>
#include <string>

int count_height(std::map<std::string, std::string>& m,
                 const std::string& name) {
  if (m[name].empty()) {
    return 0;
  }
  return count_height(m, m[name]) + 1;
}

int main(void) {
  int n = 0;
  std::cin >> n;

  std::map<std::string, std::string> m;

  std::string name, parent;
  for (int i = 0; i < n; ++i) {
    std::cin >> name >> parent;
    m[name] = parent;
    m[parent];
  }

  for (auto& elem : m) {
    std::cout << elem.first << " " << count_height(m, elem.first) << "\n";
  }

  return 0;
}