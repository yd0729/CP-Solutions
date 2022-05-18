class Solution {
  public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // 计算 mid 是第几个数
            int count = mid / n * n;
            for (int i = mid / n + 1; i <= m; ++i) {
                count += mid / i;
            }

            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};