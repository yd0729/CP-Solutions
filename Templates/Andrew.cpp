#include <bits/stdc++.h>

using namespace std;

// 计算向量 pq 和 qr 的叉积
int cross(const vector<int>& p, const vector<int>& q, const vector<int>& r) {
  return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
}

// andrew 算法：计算二维点集 points 的凸包，按逆时针方向返回构成凸包的点．
vector<vector<int>> andrew(vector<vector<int>>& points) {
  int n = points.size();
  if (n < 4) {
    return points;
  }
  /* 按照 x 大小进行排序，如果 x 相同，则按照 y 的大小进行排序 */
  sort(points.begin(), points.end(),
       [](const vector<int>& a, const vector<int>& b) {
         if (a[0] == b[0]) {
           return a[1] < b[1];
         }
         return a[0] < b[0];
       });
  vector<int> hull;
  vector<bool> used(n, false);
  /* hull[0] 需要入栈两次，不进行标记 */
  hull.emplace_back(0);
  /* 求出凸包的下半部分 */
  for (int i = 1; i < n; i++) {
    while (hull.size() > 1 && cross(points[hull[hull.size() - 2]],
                                    points[hull.back()], points[i]) < 0) {
      used[hull.back()] = false;
      hull.pop_back();
    }
    used[i] = true;
    hull.emplace_back(i);
  }
  int m = hull.size();
  /* 求出凸包的上半部分 */
  for (int i = n - 2; i >= 0; i--) {
    if (!used[i]) {
      while (hull.size() > m && cross(points[hull[hull.size() - 2]],
                                      points[hull.back()], points[i]) < 0) {
        used[hull.back()] = false;
        hull.pop_back();
      }
      used[i] = true;
      hull.emplace_back(i);
    }
  }
  /* hull[0] 同时参与凸包的上半部分检测，因此需去掉重复的 hull[0] */
  hull.pop_back();
  vector<vector<int>> res;
  for (auto& v : hull) {
    res.emplace_back(points[v]);
  }
  return res;
}