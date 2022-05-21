class Solution {
  public:
    int repeatedNTimes(vector<int> &nums) {
        int n = nums.size();
        mt19937 rand_engine{random_device{}()};
        uniform_int_distribution<int> uni_dis(0, n - 1);

        while (true) {
            int x = uni_dis(rand_engine), y = uni_dis(rand_engine);
            if (x != y && nums[x] == nums[y]) {
                return nums[x];
            }
        }
    }
};