class Solution {
  public:
    int missingNumber(vector<int> &nums) {
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] == mid) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        return nums[lo] == lo ? nums.size() : lo;
    }
};