class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        unsigned one = 0, two = 0;
        for (auto &num : nums) {
            one = (one ^ num) & ~two;
            two = (two ^ num) & ~one;
        }
        return one;
    }
};