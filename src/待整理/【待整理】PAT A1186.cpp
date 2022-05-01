/* PAT A1186.cpp
 *
 * Author: 杨东东
 * Created: Thu Mar 03 2022
 */

#ifdef YD_DEBUG
#include <cstdio>
#define debug(x) cout << #x << " = " << (x) << endl
#else
#define debug(x)
#endif

#include <bits/stdc++.h>

using namespace std;

vector<int> adj[105];
vector<bool> visited(105);

int cnt(int x) {  // start from x
  fill(visited.begin(), visited.end(), false);

  int cnt = 0;

  do {
    cnt++;
    visited[x] = true;
    int unvisit_spot = 0;

    for (int i = 0; i < adj[x].size(); i++) {
      if (not visited[adj[x][i]]) {
        unvisit_spot = adj[x][i];
        break;
      }
    }

    x = unvisit_spot;
  } while (x);

  return cnt;
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

  int n, m, a, b;
  cin >> n >> m;

  for (int i = 1; i <= m; i++) {
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    sort(adj[i].begin(), adj[i].end());
  }

  int max_cnt = 0, best_start = 0;
  for (int i = 1; i <= n; i++) {
    int cnt_i = cnt(i);

    debug(i);
    debug(cnt_i);

    if (cnt_i > max_cnt) {
      max_cnt = cnt_i;
      best_start = i;
    }
  }

  cout << best_start << " " << max_cnt;

#ifdef YD_DEBUG
  // cin.rdbuf(old_cin);
  // cout.rdbuf(old_cout);
  // fin.close();
  // fout.close();
#endif
}