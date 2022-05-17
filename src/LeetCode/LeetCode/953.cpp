class Solution {
  public:
    bool isAlienSorted(vector<string> &words, string order) {
        array<int, 256> idx;
        for (int i = 0; i < order.size(); i += 1) {
            idx[order[i]] = i;
        }
        return is_sorted(words.begin(), words.end(), [&](string &a, string &b) {
            int i = 0, j = 0;
            int n = a.size(), m = b.size();
            while (i < n and j < m) {
                if (a[i] != b[j]) {
                    return idx[a[i]] < idx[b[j]];
                }
                i += 1;
                j += 1;
            }
            return n < m;
        });
    }
};