class Solution {
  public:
    vector<int> findDuplicates(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }

        vector<int> d;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                d.push_back(nums[i]);
            }
        }

        return d;
    }
};