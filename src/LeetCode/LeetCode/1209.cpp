class Solution {
  public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stk;

        for (int i = 0; i < s.size(); i++) {
            if (stk.empty() or stk.back().first != s[i]) {
                stk.push_back({s[i], 1});
            } else {
                stk.back().second += 1;
            }
            if (stk.back().second == k) {
                stk.pop_back();
            }
        }

        string res;
        for (auto &p : stk) {
            res += string(p.second, p.first);
        }

        return res;
    }
};