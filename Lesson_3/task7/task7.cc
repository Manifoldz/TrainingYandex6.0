#include <iostream>

int main() {
  int n{0};
  unsigned long long b{0};
  std::cin >> n >> b;

  int temp{0};
  unsigned long long queue = 0, time = 0;

  for (int i = 0; i < n; ++i) {
    std::cin >> temp;
    queue += temp;
    // std::cout << queue << "\n";
    time += queue;
    if (queue < b) {
      queue = 0;
    } else {
      queue -= b;
    }
  }

  std::cout << time + queue << "\n";
  return 0;
}
