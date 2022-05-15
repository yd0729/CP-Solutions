class Solution {
  public:
    Solution() {
        croak_idx['c'] = 0;
        croak_idx['r'] = 1;
        croak_idx['o'] = 2;
        croak_idx['a'] = 3;
        croak_idx['k'] = 4;
    }

    int minNumberOfFrogs(const string &croakOfFrogs) {
        int expect_cnt[5] = {};

        for (auto &e : croakOfFrogs) {
            int idx = croak_idx[e];
            if (expect_cnt[idx] == 0) {
                if (idx == 0) {
                    expect_cnt[1] += 1;
                } else {
                    return -1;
                }
            } else {
                expect_cnt[idx] -= 1;
                expect_cnt[(idx + 1) % 5] += 1;
            }
        }

        for (int i = 1; i < 5; ++i) {
            if (expect_cnt[i] != 0) {
                return -1;
            }
        }

        return expect_cnt[0];
    }

  private:
    int croak_idx[255];
};