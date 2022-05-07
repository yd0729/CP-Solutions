class Solution {
  public:
    bool find132pattern(vector<int> &nums) {
        const int n = nums.size();

        stack<int> stk;
        vector<int> min_num{INT_MAX};

        for (int i = 0; i < n; ++i) {
            while (not stk.empty() and nums[stk.top()] <= nums[i]) {
                stk.pop();
            }

            if (not stk.empty() and min_num[stk.top()] < nums[i]) {
                return true;
            }

            stk.push(i);
            min_num.push_back(min(min_num.back(), nums[i]));
        }
        return false;
    }
};