class Solution {
  public:
    int longestIncreasingPath(vector<vector<int>> &mt) {
        this->matrix = move(mt);

        n = matrix.size();
        m = matrix[0].size();
        if (n == 0 || m == 0) {
            return 0;
        }

        memo = vector<vector<int>>(n, vector<int>(m));

        int ans = 0;

        // dijkstra
        // dijkstra();
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < m; ++j) {
        //         ans = max(ans, memo[i][j]);
        //     }
        // }

        // dfs
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = max(ans, dfs(i, j));
            }
        }

        // bfs
        // bfs();
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < m; ++j) {
        //         ans = max(ans, memo[i][j]);
        //     }
        // }

        return ans;
    }

  private:
    int n, m;

    vector<vector<int>> matrix;
    vector<vector<int>>
        memo; // memo[i][j] 表示以 (i, j) 为起点的最长递增路径长度

    static constexpr int dx[] = {0, 0, 1, -1};
    static constexpr int dy[] = {1, -1, 0, 0};

    int dfs(int x, int y) {
        if (memo[x][y]) {
            return memo[x][y];
        }

        memo[x][y] = 1;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny) &&
                matrix[nx][ny] > matrix[x][y]) { // 可以从 (x, y) 走到 (nx, ny)
                memo[x][y] = max(memo[x][y], dfs(nx, ny) + 1);
            }
        }

        return memo[x][y];
    }

    void dijkstra() {
        queue<array<int, 3>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                memo[i][j] = 1;
                q.push({i, j, 1});
            }
        }

        while (!q.empty()) {
            auto [x, y, d] = q.front();
            q.pop();

            if (d < memo[x][y]) {
                continue;
            }

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (check(nx, ny) && matrix[nx][ny] > matrix[x][y]) {
                    if (memo[nx][ny] < d + 1) {
                        memo[nx][ny] = d + 1;
                        q.push({nx, ny, d + 1});
                    }
                }
            }
        }
    }

    void bfs() {
        deque<array<int, 3>> cell;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                memo[i][j] = 1;
                cell.push_back({matrix[i][j], i, j});
            }
        }
        sort(cell.begin(), cell.end(), greater<array<int, 3>>());
        for (auto &e : cell) {
            e[0] = 1;
        }

        queue<array<int, 3>> q{cell};

        while (!q.empty()) {
            auto [_, x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (check(nx, ny) && matrix[nx][ny] > matrix[x][y]) {
                    memo[x][y] = max(memo[x][y], memo[nx][ny] + 1);
                }
            }
        }
    }

    bool check(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
};