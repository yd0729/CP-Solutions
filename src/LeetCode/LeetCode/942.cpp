class Solution {
  public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> res(n + 1);

        int mi = 0;
        int ma = n;

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'I') {
                res[i] = mi++;
            } else {
                res[i] = ma--;
            }
        }
        res[n] = mi; // 此时 mi = ma

        return res;
    }
};