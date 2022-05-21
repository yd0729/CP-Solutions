class Solution {
  public:
    int repeatedNTimes(vector<int> &nums) {
        unordered_set<int> found;
        for (int num : nums) {
            if (found.count(num)) {
                return num;
            }
            found.insert(num);
        }
        // 不可能的情况
        return -1;
    }
};