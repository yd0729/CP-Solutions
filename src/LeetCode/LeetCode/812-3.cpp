class Solution {
  private:
    int cross(const vector<int> &p, const vector<int> &q,
              const vector<int> &r) {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }

    vector<vector<int>> convex_hull(vector<vector<int>> &points) {
        int n = points.size();
        if (n < 4) {
            return points;
        }
        /* 按照 x 大小进行排序，如果 x 相同，则按照 y 的大小进行排序 */
        sort(points.begin(), points.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 if (a[0] == b[0]) {
                     return a[1] < b[1];
                 }
                 return a[0] < b[0];
             });
             
        vector<vector<int>> hull;
        /* 求出凸包的下半部分 */
        for (int i = 0; i < n; i++) {
            while (hull.size() > 1 &&
                   cross(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
                hull.pop_back();
            }
            hull.emplace_back(points[i]);
        }
        int m = hull.size();
        /* 求出凸包的上半部分 */
        for (int i = n - 2; i >= 0; i--) {
            while (hull.size() > m &&
                   cross(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
                hull.pop_back();
            }
            hull.emplace_back(points[i]);
        }
        /* hull[0] 同时参与凸包的上半部分检测，因此需去掉重复的 hull[0] */
        hull.pop_back();
        return hull;
    }

    double triangle_area(int x1, int y1, int x2, int y2, int x3, int y3) {
        return 0.5 *
               abs(x1 * y2 - y1 * x2 + x2 * y3 - y2 * x3 + x3 * y1 - y3 * x1);
    }

  public:
    double largestTriangleArea(vector<vector<int>> &points) {
        auto ch = convex_hull(points);
        int n = ch.size();
        double ret = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1, k = i + 2; j + 1 < n; j++) {
                while (k + 1 < n) {
                    double cur_area =
                        triangle_area(ch[i][0], ch[i][1], ch[j][0], ch[j][1],
                                      ch[k][0], ch[k][1]);
                    double next_area =
                        triangle_area(ch[i][0], ch[i][1], ch[j][0], ch[j][1],
                                      ch[k + 1][0], ch[k + 1][1]);
                    if (cur_area >= next_area) {
                        break;
                    }
                    k++;
                }
                double area = triangle_area(ch[i][0], ch[i][1], ch[j][0],
                                            ch[j][1], ch[k][0], ch[k][1]);
                ret = max(ret, area);
            }
        }
        return ret;
    }
};