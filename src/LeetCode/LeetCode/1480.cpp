class Solution {
  public:
    vector<int> runningSum(vector<int> &nums) {
        vector<int> res(nums.size());
        res[0] = nums[0];
        for (int i = 1; i < nums.size(); i += 1) {
            res[i] = res[i - 1] + nums[i];
        }
        return res;
    }
};