#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int val, level;
  Node *left, *right;
};

vector<int> in_order(25), pre_order(25);

Node *create(int in, int pre, int len, int level) {
  if (len == 0) return nullptr;

  int root = pre_order[pre];

  int in_pos = in;
  for (; in_pos < in + len; in_pos++) {
    if (in_order[in_pos] == root) break;
  }

  Node *n = new Node{root, level};

  int left_len = in_pos - in;
  int right_len = len - left_len - 1;

  n->left = create(in, pre + 1, left_len, level + 1);
  n->right = create(in_pos + 1, pre + 1 + left_len, right_len, level + 1);

  return n;
}

int main() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> in_order[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> pre_order[i];
  }

  Node *root = create(0, 0, N, 1);

  queue<Node *> q;
  q.push(root);

  bool first = true;
  int cur_level = 0;
  while (!q.empty()) {
    Node *front = q.front();
    q.pop();

    if (cur_level != front->level) {
      cur_level = front->level;
      if (first) {
        first = false;
      } else {
        cout << " ";
      }
      cout << front->val;
    }

    if (front->left) q.push(front->left);
    if (front->right) q.push(front->right);
  }
}