class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = target - nums[i];
            if (map.count(tmp)) {
                return {i, map[tmp]};
            }
            map[nums[i]] = i;
        }
        throw "No two sum solution";
    }
};