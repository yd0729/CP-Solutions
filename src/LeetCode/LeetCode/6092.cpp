class Solution {
  public:
    vector<int> arrayChange(vector<int> &nums,
                            vector<vector<int>> &operations) {
        unordered_map<int, int> pos;
        int n = nums.size();
        for (int i = 0; i < n; i += 1) {
            pos[nums[i]] = i;
        }

        for (auto &op : operations) {
            int &x = op[0], &y = op[1];
            nums[pos[x]] = y;
            pos[y] = pos[x];
        }

        return nums;
    }
};