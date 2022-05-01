/* 1.cpp
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

#define MAX_SIZE 10005

int opinion_cnt[MAX_SIZE * 2];
int diff[MAX_SIZE], report[MAX_SIZE], fake_cnt[MAX_SIZE];
int most_site, most_cnt = 0;

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

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= m; i++) {
    fill_n(opinion_cnt, MAX_SIZE * 2, 0);

    for (int j = 1; j <= n; j++) {
      cin >> report[j];
      opinion_cnt[report[j] + MAX_SIZE]++;
    }

    for (int j = 1; j <= n; j++) {
      diff[j] = n - opinion_cnt[report[j] + MAX_SIZE];
    }

    int max_diff = 0;
    vector<int> max_site;
    for (int j = 1; j <= n; j++) {
      if (diff[j] >= max_diff) {
        if (diff[j] > max_diff) {
          max_diff = diff[j];
          max_site.clear();
        }
        max_site.push_back(j);
      }
    }

    for (auto &e : max_site) {
      fake_cnt[e]++;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (fake_cnt[i] > most_cnt) {
      most_cnt = fake_cnt[i];
      most_site = i;
    }
  }

  cout << most_site;

#ifdef YD_DEBUG
  // cin.rdbuf(old_cin);
  // cout.rdbuf(old_cout);
  // fin.close();
  // fout.close();
#endif
}