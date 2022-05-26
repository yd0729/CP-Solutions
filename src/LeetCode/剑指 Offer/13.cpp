class Solution {
  public:
    int movingCount(int m, int n, int k) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visit(m, vector<bool>(n));

        q.emplace(0, 0);
        visit[0][0] = true;

        int cnt = 0;
        while (not q.empty()) {
            int size = q.size();
            while (size--) {
                cnt += 1;

                auto [x, y] = q.front();
                q.pop();

                for (int i = 0; i < 4; i += 1) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 and nx < m and ny >= 0 and ny < n and
                        not visit[nx][ny]) {
                        visit[nx][ny] = true;
                        if (digit_sum(nx) + digit_sum(ny) <= k) {
                            q.emplace(nx, ny);
                        }
                    }
                }
            }
        }

        return cnt;
    }

  private:
    static constexpr int dx[4] = {0, 0, 1, -1};
    static constexpr int dy[4] = {1, -1, 0, 0};

    int digit_sum(int x) {
        int sum = 0;
        while (x) {
            sum += (x % 10);
            x /= 10;
        }
        return sum;
    }
};