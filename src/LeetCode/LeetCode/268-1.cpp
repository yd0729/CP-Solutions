class Solution {
  public:
    int missingNumber(vector<int> &nums) {
        int n = nums.size();
        int missing = n;
        for (int i = 0; i < n; ++i) {
            for (int j = i; nums[j] != j;) {
                if (nums[j] == n) {
                    missing = j;
                    break;
                }
                swap(nums[j], nums[nums[j]]);
            }
        }
        return missing;
    }
};