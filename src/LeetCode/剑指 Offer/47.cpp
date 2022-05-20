class Solution {
  public:
    int maxValue(vector<vector<int>> &g) {
        this->grid = move(g);
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i += 1) {
            for (int j = 0; j < n; j += 1) {
                grid[i][j] += max(val(i - 1, j), val(i, j - 1));
            }
        }

        return grid[m - 1][n - 1];
    }

  private:
    int m, n;
    vector<vector<int>> grid;

    int val(int x, int y) {
        if (x < 0 or x >= m or y < 0 or y >= n) {
            return 0;
        }
        return grid[x][y];
    }
};