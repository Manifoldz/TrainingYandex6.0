#include <iostream>
#include <map>
#include <vector>

struct Node {
  bool used = false;
  int count_children = 0;
  std::vector<int> connected;
};

int Size(std::map<int, Node>& m, int val) {
  m[val].used = true;
  int res = 1;
  for (size_t i = 0; i < m[val].connected.size(); ++i) {
    if (m[m[val].connected[i]].used == false) {
      // std::cout << "started " << m[val].connected[i] << "\n";
      res += Size(m, m[val].connected[i]);
    }
  }
  // std::cout << "counted for " << val << " children " << res << "\n";
  m[val].count_children = res;
  return res;
}

int main(void) {
  int v = 0;
  std::cin >> v;

  std::map<int, Node> m;

  int left{0}, right{0};
  for (int i = 0; i < v - 1; ++i) {
    std::cin >> left >> right;

    m[right].connected.push_back(left);
    m[left].connected.push_back(right);
  }
  Size(m, 1);

  for (auto& elem : m) {
    // std::cout << elem.first << "-";
    // for (size_t i = 0; i < elem.second.connected.size(); ++i) {
    //   std::cout << elem.second.connected[i] << " ";
    // }
    // std::cout << "\n";
    std::cout << elem.second.count_children << " ";
  }

  return 0;
}