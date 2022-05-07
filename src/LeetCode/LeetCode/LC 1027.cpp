class Solution {
  public:
    int longestArithSeqLength(vector<int> &nums) {
        int res = 0;
        for (int dif = -500; dif <= 500; ++dif) {
            for (auto &e : nums) {
                int pre = e - dif;
                if (pre < 0 or pre > 500) {
                    dp[dif + 500][e] = 1;
                } else {
                    dp[dif + 500][e] = dp[dif + 500][pre] + 1;
                }
                res = max(res, dp[dif + 500][e]);
            }
        }
        return res;
    }

  private:
    int dp[1001][501] = {};
};