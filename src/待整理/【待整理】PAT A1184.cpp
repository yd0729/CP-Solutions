/* PAT 1184.cpp
 *
 * Author: Author
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

#define MAX_SIZE 10005

int init_cnt = 1;
int init_addr[MAX_SIZE], len[MAX_SIZE];

void cnt(int addr, int n) {
  for (int i = 0; i < n; i++) {
    if (addr < len[i]) {
      init_cnt = max(init_cnt, i + 1);
      cout << init_addr[i] + 4 * addr << "\n";
      return;
    } else {
      addr -= len[i];
    }
  }
  cout << "Illegal Access\n";
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

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> init_addr[i] >> len[i];
  }

  int q;
  for (int i = 0; i < k; i++) {
    cin >> q;
    cnt(q, n);
  }

  cout << init_cnt;

#ifdef YD_DEBUG
  // cin.rdbuf(old_cin);
  // cout.rdbuf(old_cout);
  // fin.close();
  // fout.close();
#endif
}