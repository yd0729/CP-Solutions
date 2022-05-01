/* 3.cpp
 *
 * Author: 杨东东
 * Created: Fri Mar 04 2022
 */

#ifdef YD_DEBUG
#include <cstdio>
#define debug(x) cout << #x << " = " << (x) << endl
#else
#define debug(x)
#endif

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int cnt = 0;  // 这道题容易超时，需要按需计算，记录结果
  vector<int> child;
} node[100005];

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
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, senior;
  cin >> n;

  for (int i = 2; i <= n; i++) {
    cin >> senior;
    node[senior].child.push_back(i);
  }

  int m;
  cin >> m;

  for (int i = 1; i <= m; i++) { 
    cin >> senior;

    if (not node[senior].cnt) {
      queue<int> q;
      q.push(senior);
      int cnt = 0;

      while (not q.empty()) {
        int f = q.front();
        q.pop();

        if (not node[f].cnt) {
          ++cnt;

          for (auto &e : node[f].child) {
            q.push(e);
          }
        } else {
          cnt += node[f].cnt;
        }
      }

      node[senior].cnt = cnt;
    }
    
    cout << node[senior].cnt << "\n";
  }

#ifdef YD_DEBUG
  // cin.rdbuf(old_cin);
  // cout.rdbuf(old_cout);
  // fin.close();
  // fout.close();
#endif
}