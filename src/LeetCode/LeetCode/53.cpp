class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        int sum = nums[0];
        int max_sum = sum;

        for (int i = 1; i < n; i++) {
            sum = max(nums[i], sum + nums[i]);
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};