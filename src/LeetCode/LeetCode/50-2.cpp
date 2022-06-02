class Solution {
  public:
    double myPow(double x, int n) {
        if (n < 0) {
            return quick_pow(1 / x, -(n + 1)) / x; // 处理最小值
        } else {
            return quick_pow(x, n);
        }
    }

  private:
    double quick_pow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (x == 0) {
            return 0;
        }

        double a = n % 2 ? x : 1;
        double b = quick_pow(x * x, n / 2);
        return a * b;
    }
};