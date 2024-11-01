
#include <iostream>
#include <vector>

int main(void) {
  int n{0}, k{0};
  std::cin >> n >> k;

  std::vector<int> v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
  }

  int last{0}, sum{0}, counter{0};
  for (int first = 0; first < n; first++) {
    while (last < n && sum <= k) {
      if (sum == k) {
        ++counter;
      }
      sum += v[last];
      ++last;
    }
    if (sum == k) {
      ++counter;
    }
    sum -= v[first];
  }

  std::cout << counter;

  return 0;
}