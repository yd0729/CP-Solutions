class Solution {
  public:
    double myPow(double x, int n) {
        double ans = 1;

        if (n < 0) {
            x = 1 / x;
            if (n == INT_MIN) { // 处理最小值
                n += 1;
                ans = x;
            }
            n = -n;
        }

        while (n and ans) {
            if (n & 1) {
                ans *= x;
            }
            n >>= 1;
            x *= x;
        }
        return ans;
    }
};