class Solution {
  public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int n = croakOfFrogs.size();

        if (n % 5) {
            return -1;
        }

        unordered_map<char, int> char_cnt;
        for (auto &e : croakOfFrogs) {
            char_cnt[e] += 1;
        }
        for (auto &e : croak) {
            if (char_cnt[e] != n / 5) {
                return -1;
            }
        }

        int frog_cnt = 0;
        queue<int> q[5];

        for (int i = 0; i < n; i++) {
            int idx = croak_idx.at(croakOfFrogs[i]);
            if (q[idx].empty()) {
                if (idx == 0) {
                    q[1].push(++frog_cnt);
                } else {
                    return -1;
                }
            } else {
                int f = q[idx].front();
                q[idx].pop();

                if (idx != 4) {
                    q[idx + 1].push(f);
                } else {
                    q[0].push(f);
                }
            }
        }

        for (int i = 1; i < 5; ++i) {
            if (not q[i].empty()) {
                return -1;
            }
        }

        return frog_cnt;
    }

  private:
    static const string croak;
    static const unordered_map<char, int> croak_idx;
};

const string Solution::croak = "croak";
const unordered_map<char, int> Solution::croak_idx = {
    {'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}};