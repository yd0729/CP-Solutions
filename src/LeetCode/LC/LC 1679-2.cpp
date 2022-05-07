class Solution {
  public:
    int maxOperations(vector<int> &nums, int k) {
        int res = 0;
        unordered_map<int, int> cnt;

        for (auto &e : nums) {
            if (cnt[k - e]) {
                ++res;
                --cnt[k - e];
            } else {
                ++cnt[e];
            }
        }

        return res;
    }
};