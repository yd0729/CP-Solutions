// 二叉搜索树
// 左子树小于
// 右子树大于等于

#include <bits/stdc++.h>

using namespace std;

void in_trav(vector<int> &tree, vector<int> &in_order, int id) {
  int size = tree.size();
  if (id * 2 < size and tree[id * 2] != -1) {
    in_trav(tree, in_order, id * 2);
  }

  in_order.push_back(tree[id]);

  if (id * 2 + 1 < size and tree[id * 2 + 1] != -1) {
    in_trav(tree, in_order, id * 2 + 1);
  }
}

int main() {
#ifdef YD_DEBUG
  freopen("../in", "r", stdin);
  freopen("../out", "w", stdout);
#endif

  int n;
  cin >> n;

  vector<int> tree(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> tree[i];
  }

  vector<int> in_order;
  in_trav(tree, in_order, 1);

  if (is_sorted(in_order.begin(), in_order.end())) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  for (int i = 0; i < in_order.size(); i++) {
    cout << in_order[i] << (i + 1 == in_order.size() ? "" : " ");
  }
}
