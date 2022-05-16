class Solution {
  public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        if (grid[0][0] == 1) {
            return -1;
        }

        this->n = grid.size();

        queue<array<int, 3>> q;
        q.push({0, 0, 1});
        grid[0][0] = 1;

        while (not q.empty()) {
            auto [x, y, cnt] = q.front();
            q.pop();

            if (x == n - 1 and y == n - 1) {
                return cnt;
            }

            for (int i = 0; i < 8; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (check(nx) and check(ny) and grid[nx][ny] == 0) {
                    grid[nx][ny] = 1;
                    q.push({nx, ny, cnt + 1});
                }
            }
        }

        return -1;
    }

  private:
    int n;

    static constexpr int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
    static constexpr int dy[] = {-1, 1, 0, 1, -1, 0, 1, -1};

    bool check(int &x) { return x >= 0 and x < n; }
};