class Solution {
  public:
    int consecutiveNumbersSum(int n) {
        n /= (n - (n & (n - 1))); // 直接除掉所有的 2

        int ans = 0;

        for (int i = 1; i * i < n; i++) {
            if (n % i == 0) {
                ans += 2; // 奇因子成对出现
            }
        }

        if (pow((int)sqrt(n), 2) == n) {
            ans++; // 平方数
        }

        return ans;
    }
};