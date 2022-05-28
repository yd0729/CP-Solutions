class Solution {
  public:
    int missingNumber(vector<int> &nums) {
        unordered_set<int> set;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            set.insert(nums[i]);
        }
        int missing = n;
        for (int i = 0; i < n; i++) {
            if (!set.count(i)) {
                missing = i;
                break;
            }
        }
        return missing;
    }
};