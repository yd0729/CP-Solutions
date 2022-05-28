class Solution {
  public:
    int findClosest(vector<string> &words, string word1, string word2) {
        int n = words.size();
        unordered_map<string, vector<int>> word_pos;
        for (int i = 0; i < n; i += 1) {
            word_pos[words[i]].push_back(i);
        }

        auto &v1 = word_pos[word1];
        if (v1.empty()) {
            return -1;
        }
        int len1 = v1.size();

        auto &v2 = word_pos[word2];
        if (v2.empty()) {
            return -1;
        }
        int len2 = v2.size();

        int a = 0, b = 0;
        int dis = INT_MAX;
        while (a < len1 and b < len2) {
            dis = min(dis, abs(v1[a] - v2[b]));
            if (v1[a] < v2[b]) {
                a += 1;
            } else {
                b += 1;
            }
        }

        return dis;
    }
};