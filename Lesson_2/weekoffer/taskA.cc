#include <iostream>
#include <vector>

int main(void) {
  int n = 0;
  std::cin >> n;

  std::vector<int> v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
  }

  int sum = 0;
  for (int j = 1; j < n; j++) {
    int delta = v[j] - v[j - 1];
    if (delta < 0) {
      std::cout << -1;
      return 0;
    }
    sum += delta;
  }

  std::cout << sum;

  return 0;
}
