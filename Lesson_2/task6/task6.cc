#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  int n = 0;
  std::cin >> n;

  std::vector<int> v(n);
  std::vector<int> pv(n + 1);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
    pv[i + 1] = (pv[i] + v[i]) % 1000000007;
  }

  unsigned long long sum = 0, mul = 0;
  int left = n - 2;

  while (left != 0) {
    mul = (pv[n] - pv[left + 1] + 1000000007) % 1000000007;  // sum right
    mul = (mul * pv[left]) % 1000000007;                     // sum left
    mul = (mul * v[left--]) % 1000000007;                    // current
    sum = (sum + mul) % 1000000007;
  }

  std::cout << sum;
  return 0;
}