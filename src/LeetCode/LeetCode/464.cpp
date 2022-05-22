class Solution {
  public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        n = maxChoosableInteger;
        tot = desiredTotal;

        if ((1 + n) * (n) / 2 < tot) {  // 全拿也不行
            return false;
        }

        if (tot == 0) {  // 直接获胜
            return true;
        }

        memo.fill(0);
        return dfs(0, 0) == 1;
    }

  private:
    int n;
    int tot;
    array<int, 1 << 20> memo;

    int dfs(int state, int cur_tot) {
        if (memo[state] == 0) {
            memo[state] = -1;
            for (int i = 0; i < n; i++) {
                if (((state >> i) & 1) == 0) {
                    if (i + 1 + cur_tot >= tot) {
                        memo[state] = 1;
                        break;
                    }
                    if (dfs(state | (1 << i), cur_tot + i + 1) == -1) {
                        memo[state] = 1;
                        break;
                    }
                }
            }
        }
        return memo[state];
    }
};