#include <iostream>
#include <vector>

int main() {
  int n{0};
  std::cin >> n;

  std::vector<unsigned long long> v;
  v.reserve(n);
  v.push_back(0);

  char ch = '\0';
  unsigned long long temp{0};
  while (std::cin >> ch) {
    if (ch == '+') {
      std::cin >> temp;
      v.push_back(temp + v.back());
    } else if (ch == '-') {
      std::cout << v.back() - v[v.size() - 2] << "\n";
      v.pop_back();
    } else {
      std::cin >> temp;
      std::cout << v.back() - v[v.size() - 1 - temp] << "\n";
    }
  }

  //   for (auto i : v) {
  //     std::cout << i << "\n";
  //   }

  return 0;
}