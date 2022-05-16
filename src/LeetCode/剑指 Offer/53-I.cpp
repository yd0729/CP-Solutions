class Solution {
  public:
    int search(vector<int> &nums, int target) {
        int cnt = 0;
        for (auto &e : nums) {
            if (target == e) {
                cnt += 1;
            }
        }
        return cnt;
    }
};