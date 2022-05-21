class Solution {
  public:
    bool isUnique(string astr) {
        sort(astr.begin(), astr.end());
        return unique(astr.begin(), astr.end()) == astr.end();
    }
};