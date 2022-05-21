class Solution {
  public:
    bool CheckPermutation(string s1, string s2) {
        unordered_map<char, int> m1, m2;
        for (auto &e : s1) {
            m1[e] += 1;
        }
        for (auto &e : s2) {
            m2[e] += 1;
        }
        return m1 == m2;
    }
};