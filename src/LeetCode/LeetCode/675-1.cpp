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

        int step = 0;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.emplace(sx, sy);
        visited[sx][sy] = true;

        while (!q.empty()) {
            step++;

            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();

                for (int j = 0; j < 4; ++j) {
                    int nx = x + dx[j];
                    int ny = y + dy[j];

                    if (check(nx, ny) and not visited[nx][ny] and
                        forest[nx][ny] > 0) {
                        if (nx == tx && ny == ty) {
                            return step;
                        }
                        
                        q.emplace(nx, ny);
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        return -1;
    }

    bool check(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }
};