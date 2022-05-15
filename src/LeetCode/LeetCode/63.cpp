class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> dp(m + 1);
        dp[1] = 1;

        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= m; ++i) {
                if (obstacleGrid[i - 1][j - 1]) {
                    dp[i] = 0;
                } else {
                    dp[i] += dp[i - 1];
                }
            }
        }

        return dp[m];
    }
};