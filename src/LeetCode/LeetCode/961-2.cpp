class Solution {
  public:
    int repeatedNTimes(vector<int> &nums) {
        int n = nums.size();
        int max_gap = (n == 4 ? 3 : 2);
        for (int gap = 1; gap <= max_gap; ++gap) {
            for (int i = 0; i + gap < n; ++i) {
                if (nums[i] == nums[i + gap]) {
                    return nums[i];
                }
            }
        }
        // 不可能的情况
        return -1;
    }
};