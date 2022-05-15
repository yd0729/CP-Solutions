class Solution {
  public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int l = 0;
        int r = 0;

        int p = 1;
        int cnt = 0;
        int size = nums.size();

        while (r < size) {
            p *= nums[r++];
            while (p >= k and l < r) {
                p /= nums[l++];
            }
            cnt += r - l;
        }

        return cnt;
    }
};
