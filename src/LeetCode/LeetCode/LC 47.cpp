class Solution {
  public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        ans.clear();
        vis.resize(nums.size());

        sort(nums.begin(), nums.end());
        permute(nums, 0);
        return ans;
    }

  private:
    vector<int> vis;
    vector<int> backtrack;
    vector<vector<int>> ans;

    void permute(vector<int> &nums, int idx) {
        if (idx == nums.size()) {
            ans.emplace_back(backtrack);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (vis[i] ||
                (i > 0 and nums[i] == nums[i - 1] and not vis[i - 1])) {
                continue;
            }
            backtrack.emplace_back(nums[i]);
            vis[i] = 1;
            permute(nums, idx + 1);
            vis[i] = 0;
            backtrack.pop_back();
        }
    }
};