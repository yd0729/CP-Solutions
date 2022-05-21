class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        // 数组大小为 amount + 1 ，初始值也为 amount + 1
        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;                            // base case
        for (int i = 0; i < dp.size(); i++) { // 外层 for 循环遍历所有取值
            for (int coin : coins) { // 内层 for 循环求所有选择的最小值
                if (i - coin < 0) {
                    continue;
                }
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};