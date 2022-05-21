class Solution {
  public:
    bool isUnique(string astr) {
        unordered_set<char> cnt;
        for (auto &e : astr) {
            if (cnt.count(e)) {
                return false;
            }
            cnt.insert(e);
        }
        return true;
    }
};