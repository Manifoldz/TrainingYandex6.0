#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  int n{0};
  std::cin >> n;

  std::vector<int> v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
  }
  std::sort(v.begin(), v.end());

  int right = n / 2;
  int left = right - 1;

  if (n % 2 == 1) {
    std::cout << v[right] << " ";
    ++right;
  }

  while (right < n) {
    std::cout << v[left--] << " ";
    std::cout << v[right++] << " ";
  }

  return 0;
}