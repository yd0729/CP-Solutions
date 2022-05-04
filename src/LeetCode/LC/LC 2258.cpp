class Solution {
  public:
    int maximumMinutes(vector<vector<int>> &g) {
        this->grid = move(g);

        m = grid.size();
        n = grid[0].size();
        queue<array<int, 2>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fire[i][j] = 0;
                    q.push({i, j});
                } else {
                    fire[i][j] = 1e9;
                }
            }
        }

        while (not q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (is_vaild(nx, ny) and fire[nx][ny] == 1e9) {
                    fire[nx][ny] = fire[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        memset(late, -1, sizeof late);
        late[m - 1][n - 1] = fire[m - 1][n - 1];

        priority_queue<array<int, 3>> pq;
        pq.push({late[m - 1][n - 1], m - 1, n - 1});

        while (not pq.empty()) {
            auto [d, x, y] = pq.top();
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (is_vaild(nx, ny)) {
                    int nd = pre(min(d, fire[nx][ny]));
                    if (late[nx][ny] < nd) {
                        late[nx][ny] = nd;
                        pq.push({nd, nx, ny});
                    }
                }
            }
        }

        return late[0][0];
    }

  private:
    int m;
    int n;

    int fire[305][305];
    int late[305][305];
    vector<vector<int>> grid;

    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};

    inline bool is_vaild(int &x, int &y) {
        if (x >= 0 and x < m and y >= 0 and y < n) {
            return grid[x][y] != 2;
        }
        return false;
    }

    inline int pre(int x) { return x == 1e9 ? x : x - 1; }
};