class Solution {
  public:
    int maxProduct(vector<string> &words) {
        unordered_map<int, int> map;

        int size = words.size();
        for (int i = 0; i < size; i++) {
            int mask = 0;
            string word = words[i];
            int word_size = word.size();

            for (int j = 0; j < word_size; j++) {
                mask |= 1 << (word[j] - 'a');
            }
            map[mask] = max(map[mask], word_size);  // 保留最长的单词
        }

        int res = 0;
        for (auto &[m1, size1] : map) {
            for (auto &[m2, size2] : map) {
                if ((m1 & m2) == 0) {
                    res = max(res, size1 * size2);
                }
            }
        }
        return res;
    }
};