class Solution {
  public:
    vector<int> exchange(vector<int> &nums) {
        int i = 0;
        int j = nums.size() - 1;

        while (i < j) {
            if (nums[i] % 2 == 0) {
                swap(nums[i], nums[j--]);
            } else {
                i += 1;
            }
            if (nums[j] % 2 == 1) {
                swap(nums[i++], nums[j]);
            } else {
                j -= 1;
            }
        }

        return nums;
    }
};