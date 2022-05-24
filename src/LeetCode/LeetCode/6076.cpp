class Solution {
  public:
    int minimumLines(vector<vector<int>> &stockPrices) {
        int n = stockPrices.size();
        if (n <= 2) {
            return n == 2;
        }

        sort(stockPrices.begin(), stockPrices.end());

        int cnt = 1;
        int x1 = stockPrices[0][0], y1 = stockPrices[0][1];
        int x2 = stockPrices[1][0], y2 = stockPrices[1][1];

        for (int i = 2; i < n; i += 1) {
            int x3 = stockPrices[i][0], y3 = stockPrices[i][1];

            if (not is_same(x1, y1, x2, y2, x3, y3)) {
                cnt += 1;
            }

            x1 = x2, y1 = y2;
            x2 = x3, y2 = y3;
        }

        return cnt;
    }

    bool is_same(int x1, int y1, int x2, int y2, int x3, int y3) {
        return (long long)(y2 - y1) * (x3 - x1) ==
               (long long)(y3 - y1) * (x2 - x1);
    }
};