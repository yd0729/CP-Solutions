class Solution {
  public:
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        int n = intervals.size();

        vector<array<int, 2>> l(n), r(n);
        for (int i = 0; i < n; ++i) {
            l[i][0] = intervals[i][0];
            l[i][1] = i;
            r[i][0] = intervals[i][1];
            r[i][1] = i;
        }

        sort(l.begin(), l.end());
        sort(r.begin(), r.end());

        vector<int> res(n);
        for (int i = 0, j = 0; j < n; ++j) {
            while (i < n and l[i][0] < r[j][0]) {
                i += 1;
            }
            res[r[j][1]] = i < n ? l[i][1] : -1;
        }

        return res;
    }
};