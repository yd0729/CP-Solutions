class Solution {
  public:
    char firstUniqChar(string s) {
        unordered_map<char, int> position;
        queue<char> q;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (!position.count(s[i])) { // 第 1 次出现，加入队列
                position[s[i]] = i;
                q.emplace(s[i]);
            } else { // > 1 次出现
                position[s[i]] = -1;
                while (!q.empty() && position[q.front()] == -1) {
                    q.pop();
                }
            }
        }
        return q.empty() ? ' ' : q.front();
    }
};