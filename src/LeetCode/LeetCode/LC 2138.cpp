class Solution {
  public:
    vector<string> divideString(string &s, int k, char fill) {
        vector<string> res((s.size() + k - 1) / k);

        for (int i = 0, j = 0; i < s.size(); i += k) {
            res[j++] = s.substr(i, k);
        }

        if (res.back().size() < k) {
            res.back() += string(k - res.back().size(), fill);
        }

        return res;
    }
};