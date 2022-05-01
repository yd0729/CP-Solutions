/* 2.cpp
 * 
 * Author: 杨东东
 * Created: Fri Mar 04 2022
 */

#ifdef YD_DEBUG
#include <cstdio>
#define debug(x) cout << #x << " = " << (x) << endl;
#else
#define debug(x)
#endif

#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 100005

struct Node {
  int next, rank;
} node[MAX_SIZE];

bool has_pre[MAX_SIZE];

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
    cin >> node[i].next;
    if (node[i].next != -1) {
      has_pre[node[i].next] = true;
    }
  }

  int root = 0;
  for (int i = 0; i < n; i++) {
    if (not has_pre[i]) {
      root = i;
      break;
    }
  }

  for (int i = root, rank = 1; i != -1; i = node[i].next, ++rank) {
    node[i].rank = rank;
  }

  for (int i = 0; i < n; i++) {
    cout << node[i].rank << (i == n - 1 ? "" : " ");
  }

#ifdef YD_DEBUG
  // cin.rdbuf(old_cin);
  // cout.rdbuf(old_cout);
  // fin.close();
  // fout.close();
#endif
}