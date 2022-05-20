class Solution {
  public:
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        vector<pair<int, int>> l;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            l.emplace_back(intervals[i][0], i);
        }
        sort(l.begin(), l.end());

        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(l.begin(), l.end(),
                                  make_pair(intervals[i][1], 0));
            if (it != l.end()) {
                ans[i] = it->second;
            }
        }
        return ans;
    }
};