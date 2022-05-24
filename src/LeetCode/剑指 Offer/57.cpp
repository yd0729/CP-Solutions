class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int i = 0;
        int j = nums.size() - 1;

        while (true) {
            int sum = nums[i] + nums[j];
            if (sum == target) {
                return {nums[i], nums[j]};
            } else if (sum < target) {
                i += 1;
            } else {
                j -= 1;
            }
        }
    }
};