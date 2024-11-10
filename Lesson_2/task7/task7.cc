#include <iostream>
#include <vector>

int main(void) {
  int n = 0;
  unsigned long long c = 0;
  std::cin >> n >> c;

  std::vector<char> v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
  }

  int left = 0, right = 0, maximum = 0, counter_a = 0, counter_b = 0;
  unsigned long long censor = 0;

  while (right < n) {
    if (v[right] == 'a') {
      ++counter_a;
    } else if (v[right] == 'b') {
      censor += counter_a;
      ++counter_b;
    }
    while (censor > c) {
      if (v[left] == 'a') {
        censor -= counter_b;
        --counter_a;
      } else if (v[left] == 'b') {
        --counter_b;
      }
      ++left;
    }
    ++right;
    maximum = std::max(maximum, right - left);
  }

  std::cout << maximum;

  return 0;
}
