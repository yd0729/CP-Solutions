class Solution {
  private:
    int cross(const vector<int> &p, const vector<int> &q,
              const vector<int> &r) {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }
    int distance(const vector<int> &p, const vector<int> &q) {
        return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
    }
    vector<vector<int>> convex_hull(vector<vector<int>> &trees) {
        int n = trees.size();
        if (n < 4) {
            return trees;
        }
        int bottom = 0;
        /* 找到 y 最小的点 bottom*/
        for (int i = 0; i < n; i++) {
            if (trees[i][1] < trees[bottom][1]) {
                bottom = i;
            }
        }
        swap(trees[bottom], trees[0]);
        /* 以 bottom 原点，按照极坐标的角度大小进行排序 */
        sort(trees.begin() + 1, trees.end(),
             [&](const vector<int> &a, const vector<int> &b) {
                 int diff = cross(trees[0], a, b);
                 if (diff == 0) {
                     return distance(trees[0], a) < distance(trees[0], b);
                 } else {
                     return diff > 0;
                 }
             });

        stack<int> st;
        st.emplace(0);
        st.emplace(1);
        for (int i = 2; i < n; i++) {
            int top = st.top();
            st.pop();
            /* 如果当前元素与栈顶的两个元素构成的向量顺时针旋转，则弹出栈顶元素
             */
            while (!st.empty() &&
                   cross(trees[st.top()], trees[top], trees[i]) <= 0) {
                top = st.top();
                st.pop();
            }
            st.emplace(top);
            st.emplace(i);
        }

        vector<vector<int>> res;
        while (!st.empty()) {
            res.emplace_back(trees[st.top()]);
            st.pop();
        }
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