// 找出前 K 个最大的数，并按照降序输出

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef YD_DEBUG
  freopen("../in.txt", "r", stdin);
  freopen("../out.txt", "w", stdout);
#endif
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, k, x;
  cin >> n >> k;

  priority_queue<int, vector<int>, greater<int>> pq;

  while (n--) {
    cin >> x;

    if (pq.size() < k) {
      pq.push(x);
    } else if (pq.top() < x) {
      pq.pop();
      pq.push(x);
    }
  }

  vector<int> k_max;

  while (not pq.empty()) {
    k_max.push_back(pq.top());
    pq.pop();
  }

  for (auto i = k_max.rbegin(); i != k_max.rend(); i++) {
    cout << *i << (i + 1 == k_max.rend() ? "" : " ");
  }
}
