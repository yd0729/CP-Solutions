class Solution {
  private:
    int cross(const vector<int> &p, const vector<int> &q,
              const vector<int> &r) {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }

    int distance(const vector<int> &p, const vector<int> &q) {
        return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
    }
    vector<vector<int>> convex_hull(vector<vector<int>> &points) {
        int n = points.size();
        if (n < 4) {
            return points;
        }

        int leftMost = 0;
        for (int i = 0; i < n; i++) {
            if (points[i][0] < points[leftMost][0] ||
                (points[i][0] == points[leftMost][0] &&
                 points[i][1] < points[leftMost][1])) {
                leftMost = i;
            }
        }

        vector<vector<int>> res;
        int p = leftMost;
        do {
            int q = (p + 1) % n;
            int dist_q = distance(points[p], points[q]);
            for (int r = 0; r < n; r++) {
                /* 如果 r 在 pq 的右侧，则 q = r */
                int c = cross(points[p], points[q], points[r]);
                if (c < 0) {
                    q = r;
                } else if (c == 0) {
                    int dist_r = distance(points[p], points[r]);
                    if (dist_r > dist_q) {
                        dist_q = dist_r;
                        q = r;
                    }
                }
            }
            res.emplace_back(points[q]);

            p = q;
        } while (p != leftMost);
        return res;
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