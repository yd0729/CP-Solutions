class Solution {
  public:
    int minimumSwitchingTimes(vector<vector<int>> &source,
                              vector<vector<int>> &target) {
        for (auto &l : source) {
            for (auto &e : l) {
                ++color_cnt[e];
            }
        }

        for (auto &l : target) {
            for (auto &e : l) {
                if (color_cnt[e]) {
                    --color_cnt[e];
                }
            }
        }

        int res = 0;
        for (auto &e : color_cnt) {
            res += e;
        }
        return res;
    }

  private:
    array<int, 10005> color_cnt;
};