
#include <iostream>
#include <queue>
#include <vector>

int main(void) {
  int n = 0;
  std::cin >> n;

  std::vector<int> v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
  }

  int m = 0, k = 0;
  std::cin >> m >> k;

  std::vector<int> e(m);
  for (int i = 0; i < m; i++) {
    std::cin >> e[i];
  }

  std::vector<int> p(n);
  int counter = 0;
  int left = 0;
  for (int i = 1; i < n; i++) {
    if (v[i] < v[i - 1]) {
      counter = 0;
      left = i;
    }
    if (v[i] == v[i - 1]) {
      ++counter;
    }
    while (counter > k) {
      if (v[left] == v[left + 1]) {
        --counter;
      }
      ++left;
    }
    p[i] = i - left;
  }

  for (int i = 0; i < m; i++) {
    std::cout << e[i] - p[e[i] - 1] << " ";
  }

  return 0;
}