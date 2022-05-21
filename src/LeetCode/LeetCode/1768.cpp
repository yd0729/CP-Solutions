class Solution {
  public:
    string mergeAlternately(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        vector<char> sb(l1 + l2);
        for (int i = 0, j = 0, k = 0; i < l1 or j < l2;) {
            if (i < l1) {
                sb[k++] = word1[i++];
            }
            if (j < l2) {
                sb[k++] = word2[j++];
            }
        }
        return string(sb.begin(), sb.end());
    }
};