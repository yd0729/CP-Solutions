/* 4.cpp
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

// 每个包裹有一个 deadline ，在 deadline 之前送达会获得 Y 元，之后送达会获得 Y -
// P 元。 1 挣得多 2 最快 会在两点之间走最短路径，但是在中途不会送货。

// 要忽略不可能的方案
// 1. 没有送完所有包裹
// 2. 出发时间不在 8 - 17 之间

// 回来的时候可能是第二天了。

#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 1005
#define timestamp(h, m) ((h)*60 + (m))

void print_time(int t) { printf("%02d:%02d", (t / 60) % 24, t % 60); }

// package
int deadline[MAX_SIZE], y[MAX_SIZE], p[MAX_SIZE];

int min_time[MAX_SIZE][MAX_SIZE];

int read_time() {
  int h, m;
  scanf("%d:%d", &h, &m);
  return timestamp(h, m);
}

int n;

void flody() {
  for (int k = 0; k <= n; ++k)
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= n; ++j)
        min_time[i][j] = min(min_time[i][j], min_time[i][k] + min_time[k][j]);
}

void evaluate(const int &start_time, vector<int> &path, int &pay, int &time) {
  pay = 0;
  time = start_time;

  for (int i = 1; i < path.size(); i++) {
    int &u = path[i - 1];
    int &v = path[i];

    time += min_time[u][v];

#ifdef YD_DEBUG

    cout << " ";
    print_time(time);
    cout << " ";

#endif

    pay += y[v];

#ifdef YD_DEBUG

    cout << "+" << y[v];

#endif

    if (time > deadline[v]) {
      pay -= p[v];

#ifdef YD_DEBUG

      cout << "-" << p[v];

#endif
    }

#ifdef YD_DEBUG

    cout << "\n";

#endif
  }

#ifdef YD_DEBUG

  cout << pay << "\n";

#endif
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

  int m, start_time;
  cin >> n >> m;
  start_time = read_time();

  for (int i = 1; i <= n; i++) {
    deadline[i] = read_time();
    cin >> y[i] >> p[i];
  }

  int v1, v2, time;
  memset(min_time, 0x3f3f3f3f, sizeof min_time);
  for (int i = 1; i <= m; i++) {
    cin >> v1 >> v2 >> time;
    min_time[v1][v2] = min_time[v2][v1] = min(min_time[v1][v2], time);
  }

  for (int i = 0; i <= n; ++i) {
    min_time[i][i] = 0;
  }
  flody();

#ifdef YD_DEBUG

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      cout << min_time[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";

#endif

  int k;
  cin >> k;

  int max_pay = -999999999, min_end_time = 999999999;
  vector<int> plan(n + 2);
  vector<bool> checked(n + 1);
  for (int i = 0; i < k; i++) {
    fill_n(checked.begin(), n + 1, false);

    for (int j = 1; j <= n; j++) {
      cin >> plan[j];
      checked[plan[j]] = true;
    }

    bool is_possible = true;
    for (int i = 1; i <= n; i++) {
      if (not checked[i]) {
        is_possible = false;
      }
    }

    if (not is_possible) {
      continue;
    }

    int time, pay;

#ifdef YD_DEBUG

    cout << "Plan " << i + 1 << "\n";

#endif

    evaluate(start_time, plan, pay, time);

    if (pay > max_pay) {
      max_pay = pay;
      min_end_time = time;
    } else if (pay == max_pay and time < min_end_time) {
      min_end_time = time;
    }
  }

  cout << max_pay << " ";
  print_time(min_end_time);

#ifdef YD_DEBUG
  // cin.rdbuf(old_cin);
  // cout.rdbuf(old_cout);
  // fin.close();
  // fout.close();
#endif
}