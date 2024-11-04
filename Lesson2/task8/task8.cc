#include <iostream>
#include <vector>

int main(void) {
  int n = 0;
  std::cin >> n;

  std::vector<int> v(n);
  std::vector<unsigned long long> pv(n + 1);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
    pv[i + 1] = pv[i] + v[i];
  }

  unsigned long long left_sum = 0;
  unsigned long long right_sum = 0;

  for (int i = 1; i < n; i++) {
    right_sum += static_cast<unsigned long long>(v[i]) * i;
  }
  unsigned long long minimum = right_sum;

  for (int i = 1; i < n; i++) {
    left_sum += pv[i];
    right_sum -= (pv[n] - pv[i]);
    minimum = std::min(minimum, left_sum + right_sum);
  }

  std::cout << minimum;

  return 0;
}
