/* PAT A1185.cpp
 * 
 * Author: 杨东东
 * Created: Thu Mar 03 2022
 */

#ifdef YD_DEBUG
#include <cstdio>
#define debug(x) cout << #x << " = " << (x) << endl;
#else
#define debug(x)
#endif

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int key, priority, level_order;
  
  Node *l_child = nullptr, *r_child = nullptr;
} node[35];

void insert(int id, Node *&root, int level_order) {
  if (root == nullptr) {
    root = &node[id];
    root->level_order = level_order;
  } else if (root->key > node[id].key) {
    insert(id, root->l_child, 2 * level_order);
  } else {
    insert(id, root->r_child, 2 * level_order + 1);
  }
}

int main() {
#ifdef YD_DEBUG
  // 这种方法不能重定向 scanf 和 printf
  // ifstream fin("../in.txt");
  // ofstream fout("../out.txt");

  // streambuf *old_cin;
  // old_cin = cin.rdbuf(fin.rdbuf());
  // streambuf *old_cout;
  // old_cout = cout.rdbuf(fout.rdbuf());

  freopen("../in.txt", "r", stdin);
  freopen("../out.txt", "w", stdout);
#endif

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> node[i].key >> node[i].priority;
  }

  sort(node, node + n,
       [](Node &a, Node &b) { return a.priority < b.priority; });

  Node *root = nullptr;

  for (int i = 0; i < n; i++) {
    insert(i, root, 1);
  }

  sort(node, node + n,
       [](Node &a, Node &b) { return a.level_order < b.level_order; });

  for (int i = 0; i < n; i++) {
    cout << node[i].key << (i == n - 1 ? "\n" : " ");
  }

  for (int i = 0; i < n; i++) {
    cout << node[i].priority << (i == n - 1 ? "" : " ");
  }

#ifdef YD_DEBUG
  // cin.rdbuf(old_cin);
  // cout.rdbuf(old_cout);
  // fin.close();
  // fout.close();
#endif
}