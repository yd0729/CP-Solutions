class Solution {
  public:
    bool makesquare(vector<int> &matchsticks) {
        int total_len = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total_len % 4 != 0) {
            return false;
        }

        int len = total_len / 4;
        int n = matchsticks.size();
        vector<int> dp(1 << n, -1);
        dp[0] = 0;
        for (int s = 1; s < (1 << n); s++) {
            for (int k = 0; k < n; k++) {
                if ((s & (1 << k)) == 0) {  // 状态 s 没有放入第 k 根火柴
                    continue;
                }
                int s1 = s & ~(1 << k);  // 状态 s1 放入第 k 根火柴就可以转移到状态 s
                if (dp[s1] >= 0 && dp[s1] + matchsticks[k] <= len) {
                    dp[s] = (dp[s1] + matchsticks[k]) % len;  // 放满了就开始放下一条边
                    break;
                }
            }
        }
        return dp[(1 << n) - 1] == 0;
    }
};