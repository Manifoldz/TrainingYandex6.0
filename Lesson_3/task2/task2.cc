#include <iostream>
#include <stack>

struct City_t {
  int price;
  int new_place = -1;
};

int main(void) {
  int n = 0;
  std::cin >> n;
  City_t cities[n];

  for (int i = 0; i < n; i++) {
    std::cin >> cities[i].price;
  }

  std::stack<City_t *> s;

  for (int i = 0; i < n; i++) {
    while (!s.empty() && s.top()->price > cities[i].price) {
      s.top()->new_place = i;
      s.pop();
    }
    s.push(&cities[i]);
  }

  for (int i = 0; i < n; i++) {
    std::cout << cities[i].new_place << " ";
  }

  return 0;
}
