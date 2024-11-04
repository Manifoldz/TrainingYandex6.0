#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  int n = 0;
  std::cin >> n;

  std::vector<int> a(n);
  std::vector<int> b(n);
  std::vector<int> p(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
  }

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  return 0;
}
