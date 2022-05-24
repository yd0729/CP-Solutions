class Solution {
  public:
    int cutOffTree(vector<vector<int>> &f) {
        this->forest = move(f);

        vector<array<int, 2>> tree;

        m = forest.size();
        n = forest[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] > 1) {
                    tree.emplace_back(array<int, 2>{i, j});
                }
            }
        }

        sort(tree.begin(), tree.end(), [&](auto &a, auto &b) {
            return forest[a[0]][a[1]] < forest[b[0]][b[1]];
        });

        int x = 0;
        int y = 0;
        int res = 0;
        for (int i = 0; i < tree.size(); ++i) {
            int steps = bfs(x, y, tree[i][0], tree[i][1]);
            if (steps == -1) {
                return -1;
            }
            res += steps;
            x = tree[i][0];
            y = tree[i][1];
        }
        return res;
    }

  private:
    int m, n;
    vector<vector<int>> forest;
    static constexpr int dx[4]{-1, 1, 0, 0};
    static constexpr int dy[4]{0, 0, -1, 1};

    int bfs(int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty) {
            return 0;
        }

        using arr4 = array<int, 4>;
        vector<vector<int>> costed(m, vector<int>(n, INT_MAX));
        priority_queue<arr4, vector<arr4>, greater<arr4>> pq;

        costed[sx][sy] = abs(sx - tx) + abs(sy - ty);
        pq.emplace(array<int, 4>{costed[sx][sy], 0, sx, sy});

        while (!pq.empty()) {
            auto [cost, dist, x, y] = pq.top();
            pq.pop();

            if (x == tx && y == ty) {
                return dist;
            }

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (check(nx, ny) and forest[nx][ny] > 0) {
                    int ncost = dist + 1 + abs(nx - tx) + abs(ny - ty);
                    if (ncost < costed[nx][ny]) {
                        pq.emplace(array<int, 4>{ncost, dist + 1, nx, ny});
                        costed[nx][ny] = ncost;
                    }
                }
            }
        }
        return -1;
    }

    bool check(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }
};