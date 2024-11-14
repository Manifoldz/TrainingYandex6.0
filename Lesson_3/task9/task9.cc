#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

struct Car_t {
  int dir;
  int arrive;
  int depart;
};

bool carCmp(const Car_t* left, const Car_t* right) {
  return left->arrive < right->arrive;
}

int main() {
  int n{0};
  std::pair<int, int> p;
  std::cin >> n >> p.first >> p.second;
  bool is_straight = std::abs(p.second - p.first) == 2;

  std::vector<Car_t> v(n);
  std::vector<Car_t*> v2(n);

  for (int i = 0; i < n; ++i) {
    std::cin >> v[i].dir >> v[i].arrive;
    v2[i] = &v[i];
  }

  std::sort(v2.begin(), v2.end(), carCmp);

  // for (int i = 0; i < n; ++i) {
  //   std::cout << v[i].arrive << " ";
  // }

  // std::cout << "\n\n";

  std::vector<std::queue<Car_t*>> q(4);

  for (auto& i : v2) {
    // std::cout << i.dir << " " << i.arrive << "\n";
    q[i->dir - 1].push(i);
  }
  int time = 1;

  std::set<int> dirs = {1, 2, 3, 4};
  dirs.erase(p.first);
  dirs.erase(p.second);

  int third = *dirs.begin();
  int fourth = *(++dirs.begin());

  while (!q[0].empty() || !q[1].empty() || !q[2].empty() || !q[3].empty()) {
    bool is_crossed = false;
    // 1
    if (!q[p.first - 1].empty() && time >= q[p.first - 1].front()->arrive) {
      // std::cout << q[p.first - 1].empty() << "opa1\n";
      if (is_straight || p.second - p.first == 1 || p.first == 4 ||
          q[p.second - 1].empty() || time < q[p.second - 1].front()->arrive) {
        q[p.first - 1].front()->depart = time;
        q[p.first - 1].pop();
        is_crossed = true;
      }
    }
    // 2
    if (!q[p.second - 1].empty() && time >= q[p.second - 1].front()->arrive) {
      // std::cout << "opa2\n";
      if (is_straight || is_crossed == false) {
        q[p.second - 1].front()->depart = time;
        q[p.second - 1].pop();
        is_crossed = true;
      }
    }

    if (!is_crossed) {
      bool flag = false;
      if (!q[third - 1].empty() && time >= q[third - 1].front()->arrive) {
        if (is_straight || fourth - third == 1 || q[fourth - 1].empty() ||
            time < q[fourth - 1].front()->arrive) {
          q[third - 1].front()->depart = time;
          q[third - 1].pop();
          flag = true;
        }
      }
      if (!q[fourth - 1].empty() && time >= q[fourth - 1].front()->arrive) {
        if (is_straight || flag == false) {
          q[fourth - 1].front()->depart = time;
          q[fourth - 1].pop();
        }
      }
    }
    ++time;
  }

  for (int i = 0; i < n; ++i) {
    std::cout << v[i].depart << "\n";
  }

  return 0;
}