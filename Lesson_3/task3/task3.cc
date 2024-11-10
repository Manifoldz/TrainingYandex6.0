#include <deque>
#include <iostream>
#include <stack>
#include <vector>

int main(void) {
  int n = 0, k = 0;
  std::cin >> n >> k;

  std::vector<int> v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
  }

  std::deque<int> d;

  for (int i = 0; i < n; i++) {
    while (!d.empty() && d.back() > v[i]) {
      d.pop_back();
    }
    d.push_back(v[i]);

    // get minimum and delete extra from left (preparation for next iteration)
    if (i + 1 >= k) {
      std::cout << d.front() << "\n";
      if (d.front() == v[i + 1 - k]) {
        d.pop_front();
      }
    }
  }

  return 0;
}
