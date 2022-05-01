#include <iostream>

using namespace std;

int w[10005], m[10005];

int main() {
  int n;
  cin >> n;

  m[0] = 200;
  cin >> w[0];

  for (int i = 1; i < n; ++i) {
    cin >> w[i];

    if (w[i] == w[i - 1]) {  // 体重相等
      m[i] = m[i - 1];

    } else if (w[i] > w[i - 1]) {  // 体重更大
      m[i] = m[i - 1] + 100;

    } else {       // 体重更小
      m[i] = 200;  // 最少是 200

      for (int j = i - 1; j >= 0; --j) {  // 调整前边的分配
        if (w[j] > w[j + 1] and m[j] <= m[j + 1]) {
          m[j] = m[j + 1] + 100;
        } else if (w[j] == w[j + 1] and m[j] < m[j + 1]) {
          m[j] = m[j + 1];
        }
      }
    }
  }

  int sum = 0;
  for (int i = 0; i < n; ++i) sum += m[i];
  cout << sum;
}