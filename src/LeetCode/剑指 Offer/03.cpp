class Solution {
  public:
    int findRepeatNumber(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; nums[j] != j;) {
                if (nums[j] == nums[nums[j]]) {
                    return nums[j];
                }
                swap(nums[j], nums[nums[j]]);
            }
        }
        throw "no repeat number";
    }
};