class Solution {
  public:
    char firstUniqChar(string s) {
        unordered_map<char, int> position;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (position.count(s[i])) {  // > 1 次出现
                position[s[i]] = -1;
            } else {
                position[s[i]] = i;
            }
        }
        int first = n;
        for (auto [_, pos] : position) {
            if (pos != -1 && pos < first) {
                first = pos;
            }
        }
        return first == n ? ' ' : s[first];
    }
};