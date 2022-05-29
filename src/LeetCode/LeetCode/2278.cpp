class Solution {
  public:
    int percentageLetter(string s, char letter) {
        int cnt = 0;
        int n = s.size();
        for (auto &e : s) {
            if (e == letter) {
                cnt += 1;
            }
        }
        return 100 * cnt / n;
    }
};