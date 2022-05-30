class Solution {
  public:
    int rearrangeCharacters(string s, string target) {
        array<int, 256> cnt;
        cnt.fill(0);
        for (auto &e : s) {
            cnt[e] += 1;
        }

        unordered_map<int, int> cnt_t;
        for (auto &e : target) {
            cnt_t[e] += 1;
            
        }

        int res = INT_MAX;
        for (auto &e : cnt_t) {
            res = min(res, cnt[e.first] / e.second);
        }

        return res;
    }
};