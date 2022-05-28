class Solution {
  public:
    int findClosest(vector<string> &words, string word1, string word2) {
        int size = words.size();
        int res = size;
        int a = -1, b = -1;
        for (int i = 0; i < size; i++) {
            if (words[i] == word1) {
                a = i;
            } else if (words[i] == word2) {
                b = i;
            }
            if (a >= 0 && b >= 0) {
                res = min(res, abs(a - b));
            }
        }
        return res;
    }
};