class Solution {
  public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int x = abs(nums[i]);
            if (1 <= x and x <= n and nums[x - 1] > 0) {
                nums[x - 1] = -nums[x - 1];
            }
        }

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};