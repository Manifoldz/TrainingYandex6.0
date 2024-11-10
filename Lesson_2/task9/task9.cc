
#include <iostream>
#include <queue>
#include <vector>

struct Algo_t {
  int a;
  int b;
  int idx;
  bool done = false;
};

bool interestCmp(const Algo_t* left, const Algo_t* right) {
  if (left->a != right->a) return left->a < right->a;
  if (left->b != right->b) return left->b < right->b;
  return left->idx > right->idx;
}

bool usefulCmp(const Algo_t* left, const Algo_t* right) {
  if (left->b != right->b) return left->b < right->b;
  if (left->a != right->a) return left->a < right->a;
  return left->idx > right->idx;
}

int main(void) {
  int n = 0;
  std::cin >> n;

  std::vector<Algo_t> algo(n);
  for (int i = 0; i < n; i++) {
    std::cin >> algo[i].a;
    algo[i].idx = i + 1;
  }
  for (int i = 0; i < n; i++) {
    std::cin >> algo[i].b;
  }

  std::vector<int> p(n);
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
  }

  std::priority_queue<Algo_t*, std::vector<Algo_t*>, decltype(&interestCmp)>
      interestQ(interestCmp);
  std::priority_queue<Algo_t*, std::vector<Algo_t*>, decltype(&usefulCmp)>
      usefulQ(usefulCmp);

  for (int i = 0; i < n; ++i) {
    interestQ.push(&algo[i]);
    usefulQ.push(&algo[i]);
  }

  for (int i = 0; i < n; ++i) {
    Algo_t* res;
    if (p[i] == 0) {
      while (interestQ.top()->done) {
        interestQ.pop();
      }
      res = interestQ.top();
    } else {
      while (usefulQ.top()->done) {
        usefulQ.pop();
      }
      res = usefulQ.top();
    }

    res->done = true;

    std::cout << res->idx << " ";
  }

  return 0;
}