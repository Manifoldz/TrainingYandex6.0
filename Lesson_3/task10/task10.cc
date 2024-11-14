#include <algorithm>
#include <deque>
#include <iostream>
#include <limits>
#include <vector>

struct Chair_t {
  int height;
  int width;
};

bool chairCmp(const Chair_t& left, const Chair_t& right) {
  return left.height < right.height;
}

int main() {
  int n{0}, h{0};
  std::cin >> n >> h;

  std::vector<Chair_t> v(n);

  for (int i = 0; i < n; ++i) {
    std::cin >> v[i].height;
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i].width;
  }

  if (n == 1) {
    std::cout << 0;
    return 0;
  }

  std::sort(v.begin(), v.end(), chairCmp);

  for (int i = n - 1; i != 0; --i) {
    v[i].height = v[i].height - v[i - 1].height;
  }
  v[0].height = 0;

  // for (auto& i : v) {
  //   std::cout << i.height << " " << i.width << "\n";
  // }

  unsigned long long width = 0;
  int minimum = std::numeric_limits<int>::max();

  std::deque<int*> d;
  d.push_back(&v[0].height);
  int left = 0;

  for (int i = 0; i < n; i++) {
    width += v[i].width;
    while (!d.empty() && *d.back() < v[i].height) {
      d.pop_back();
    }

    d.push_back(&v[i].height);
    // std::cout << width << "\n";
    while (width >= (unsigned long long)h && !d.empty()) {
      if (left == i) {
        std::cout << 0;
        return 0;
      }
      minimum = std::min(minimum, *d.front());
      if (&v[left + 1].height == d.front()) {
        // std::cout << *d.front() << "!\n";
        d.pop_front();
      }
      width -= v[left].width;
      ++left;
    }
  }

  std::cout << minimum << "\n";

  return 0;
}