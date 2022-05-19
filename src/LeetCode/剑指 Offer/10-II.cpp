class Solution {
  public:
    int numWays(int n) { return fib(n + 1); }

    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        int pre = 0;
        int res = 1;
        for (int i = 1; i < n; i++) {
            int temp = (res + pre) % (int)(1e9 + 7);
            pre = res;
            res = temp;
        }
        return res;
    }
};