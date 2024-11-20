#include <iostream>
#include <map>
#include <string>
#include <utility>

int main(void) {
  int n = 0;
  std::cin >> n;

  std::map<std::string, std::pair<std::string, int>> m;

  std::string name, parent;
  for (int i = 0; i < n; ++i) {
    std::cin >> name >> parent;
    m[name].first = parent;
    while (!parent.empty()) {
      m[parent].second += m[name].second + 1;
      parent = m[parent].first;
    }
  }

  for (auto& elem : m) {
    std::cout << elem.first << " " << elem.second.second << "\n";
  }

  return 0;
}