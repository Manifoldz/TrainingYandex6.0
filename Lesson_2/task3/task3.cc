
#include <iostream>
#include <vector>

int main(void) {
  int n{0}, r{0};
  std::cin >> n >> r;

  std::vector<int> v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
  }

  int first{0}, last{1}, sum{0};
  unsigned long counter{0};
  for (; first < n; first++) {
    while (last < n && v[last] - v[first] <= r) {
      ++last;
    }
    if (last == n) {
      break;
    }
    if (v[last] - v[first] > r) {
      counter += n - last;
    }
  }

  std::cout << counter;

  return 0;
}