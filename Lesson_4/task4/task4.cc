#include <iostream>
#include <string>

struct Node {
  int val;
  Node *left;
  Node *right;
};

void PrintTree(Node *root, int level) {
  if (root == nullptr) {
    return;
  }
  PrintTree(root->left, level + 1);
  for (int i = 0; i < level; ++i) {
    std::cout << '.';
  }
  std::cout << root->val << '\n';
  PrintTree(root->right, level + 1);
}

std::pair<Node *, bool> Search(Node *root, int val) {
  Node *prev = root;
  // std::cout << prev << " " << false << "-searched\n";
  while (root != nullptr) {
    if (root->val == val) {
      return {root, true};
    }
    prev = root;
    if (val > root->val) {
      root = root->right;
    } else {
      root = root->left;
    }
  }
  // std::cout << prev << " " << false << "-searched\n";
  return {prev, false};
}

std::string Insert(Node **root, int val) {
  auto search = Search(*root, val);
  // std::cout << search.first << " " << search.second << "-searched\n";
  if (search.second == true) {
    return "ALREADY\n";
  }
  Node *added = new Node{val, nullptr, nullptr};

  if (search.first == nullptr) {
    *root = added;
    return "DONE\n";
  }

  if (val > search.first->val) {
    search.first->right = added;
  } else {
    search.first->left = added;
  }
  return "DONE\n";
}

int main(void) {
  std::string oper;
  int num{0};

  Node *root = nullptr;
  while (std::cin >> oper) {
    if (oper == "PRINTTREE") {
      PrintTree(root, 0);
    } else {
      // std::cout << "add\n";
      std::cin >> num;
      if (oper == "ADD") {
        std::cout << Insert(&root, num);
      } else {
        if (auto res = Search(root, num); res.second == true) {
          std::cout << "YES\n";
        } else {
          std::cout << "NO\n";
        }
      }
    }
  }

  return 0;
}