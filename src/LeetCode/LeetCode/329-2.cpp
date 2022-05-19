class Solution {
  public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        n = matrix.size();
        m = matrix[0].size();
        if (n == 0 || m == 0) {
            return 0;
        }
        // 计算每个单元格的出度
        auto out_degree = vector<vector<int>>(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (check(nx, ny) && matrix[nx][ny] > matrix[i][j]) {
                        ++out_degree[i][j];
                    }
                }
            }
        }
        // 找到出度为 0 的单元格
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (out_degree[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        // 根据拓扑排序的顺序按照层次 bfs
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();

                for (int k = 0; k < 4; ++k) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (check(nx, ny) && matrix[nx][ny] < matrix[x][y]) {
                        --out_degree[nx][ny];
                        if (out_degree[nx][ny] == 0) {
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }

        return ans;
    }

  private:
    int n, m;

    static constexpr int dx[] = {0, 0, 1, -1};
    static constexpr int dy[] = {1, -1, 0, 0};

    bool check(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
};