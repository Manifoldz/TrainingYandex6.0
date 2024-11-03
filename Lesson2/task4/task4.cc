#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  int n{0}, k{0};
  std::cin >> n >> k;

  std::vector<int> v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
  }
  std::sort(v.begin(), v.end());

  int left = 0;
  int maximum{1};
  for (int right = 0; right < n;) {
    while (right != n && v[right] - v[left] <= k) {
      ++right;
    }
    maximum = std::max(maximum, right - left);
    ++left;
  }

  std::cout << maximum;

  return 0;
}