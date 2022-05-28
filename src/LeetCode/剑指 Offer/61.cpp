class Solution {
  public:
    bool isStraight(vector<int> &nums) {
        sort(begin(nums), end(nums));

        auto i = nums.begin();
        while (*i == 0) {
            i += 1;
        }

        // 除 0 以外是否有重复的
        if (unique(i, nums.end()) != nums.end()) {
            return false;
        }

        // 除 0 以外最大值最小值只差应该不超过 4
        return *nums.rbegin() - *i <= 4;
    }
};