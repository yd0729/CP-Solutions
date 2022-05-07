class Solution {
  public:
    int maxOperations(vector<int> &nums, int k) {
        int i = 0;
        int j = nums.size() - 1;
        int cnt = 0;

        sort(nums.begin(), nums.end());

        while (i < j) {
            int sum = nums[i] + nums[j];

            if (sum < k) {
                ++i;
            } else if (sum > k) {
                --j;
            } else {
                ++i;
                --j;
                ++cnt;
            }
        }

        return cnt;
    }
}; // 事实上这个方法快