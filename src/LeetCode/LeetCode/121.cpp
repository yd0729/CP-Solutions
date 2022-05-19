class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int max_right = -1;
        int profit = 0;
        for (int i = prices.size() - 1; i >= 0; --i) {
            max_right = max(max_right, prices[i]);
            profit = max(profit, max_right - prices[i]);
        }
        return profit;
    }
};