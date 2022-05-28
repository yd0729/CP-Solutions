class Solution {
  public:
    string removeOuterParentheses(string &s) {
        string res;
        int n = s.size();
        for (int i = 0, j = 0, cnt = 0; j < n; j += 1) {
            if (s[j] == '(') {
                cnt += 1;
            } else {
                cnt -= 1;
            }
            if (cnt == 0) {
                res += s.substr(i + 1, j - i - 1);
                i = j + 1;
            }
        }

        return res;
    }
};