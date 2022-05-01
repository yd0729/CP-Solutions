// N 个多选题， 8 个选项 a-h
// 获得一个长度为 N 的 string
// 得分超过 T 的是

// f 开头 -2
// a 结尾 -1
// 每个最长的相同字母的串的长度大于 5 ，+3
// a 后面是 e 或 h -4
// 每个最长的连续增长的串的长度大于 3 ，+5

// N 问题的个数
// T 阈值
// K 测试者

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef YD_DEBUG
  freopen("../in", "r", stdin);
  freopen("../out", "w", stdout);
#endif

  int n, t, k;
  cin >> n >> t >> k;

  for (int i = 0; i < k; i++) {
    string s;
    cin >> s;

    int score = 0;

    if (s[0] == 'f') {
      score -= 2;
    }

    if (s.back() == 'a') {
      score -= 1;
    }

    for (int i = 0; i < n; i++) {
      if (s[i] == 'a') {
        if (i + 1 < n and (s[i + 1] == 'e' or s[i + 1] == 'h')) {
          score -= 4;
        }
      }
    }

    for (int i = 0; i < n;) {
      char c = s[i];
      int cnt = 1;

      int j = i + 1;

      for (; j < n; j++) {
        if (s[j] == c) {
          ++cnt;
        } else {
          break;
        }
      }

      i = j;

      if (cnt > 5) {
        score += 3;
      }
    }

    for (int i = 0; i < n;) {
      char c = s[i];
      int cnt = 1;

      int j = i + 1;

      for (; j < n; j++) {
        if (s[j] == ++c) {
          ++cnt;
        } else {
          break;
        }
      }

      i = j;

      if (cnt > 3) {
        score += 5;
      }
    }

    cout << score;
    if (score > t) {
      cout << "!!!\n";
    } else {
      cout << "\n";
    }
  }
}
