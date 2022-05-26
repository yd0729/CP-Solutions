class Solution {
  public:
    bool exist(vector<vector<char>> &board, string word) {
        len = word.size();
        m = board.size();
        n = board[0].size();
        this->word = move(word);
        this->board = move(board);

        for (auto &e : visit) {
            e.fill(false);
        }

        for (int i = 0; i < m; i += 1) {
            for (int j = 0; j < n; j += 1) {
                visit[i][j] = true;
                if (dfs(0, i, j)) {
                    return true;
                }
                visit[i][j] = false;
            }
        }

        return false;
    }

  private:
    static constexpr int dx[4] = {0, 0, 1, -1};
    static constexpr int dy[4] = {1, -1, 0, 0};

    string word;
    int len, m, n;
    vector<vector<char>> board;
    static array<array<bool, 200>, 200> visit;

    bool dfs(int cur, int x, int y) {
        if (word[cur] == board[x][y]) {
            if (cur + 1 == len) {
                return true;
            }

            for (int i = 0; i < 4; i += 1) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (check(nx, ny) and not visit[nx][ny]) {
                    visit[x][y] = true;
                    if (dfs(cur + 1, nx, ny)) {
                        return true;
                    }
                    visit[x][y] = false;
                }
            }
        }

        return false;
    }

    bool check(int x, int y) { return x >= 0 and x < m and y >= 0 and y < n; }
};

array<array<bool, 200>, 200> Solution::visit;