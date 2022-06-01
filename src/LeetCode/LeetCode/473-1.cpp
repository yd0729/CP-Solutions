class Solution {
  public:
    bool makesquare(vector<int> &matchsticks) {
        int total_len = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total_len % 4 != 0) {
            return false;
        }
        sort(matchsticks.begin(), matchsticks.end(),
             greater<int>()); // 剪枝 2

        vector<int> edges(4);
        return dfs(0, matchsticks, edges, total_len / 4);
    }

  private:
    bool dfs(int index, vector<int> &matchsticks, vector<int> &edges, int len) {
        if (index == matchsticks.size()) {
            return true;
        }
        for (int i = 0; i < edges.size(); i++) {
            bool same = false;
            for (int j = i - 1; j >= 0; --j) {
                if (edges[j] == edges[i]) {
                    same = true;
                    break;
                }
            }
            if (same) {
                continue;
            } // 剪枝 1

            edges[i] += matchsticks[index];
            if (edges[i] <= len && dfs(index + 1, matchsticks, edges, len)) {
                return true;
            }
            edges[i] -= matchsticks[index];
        }
        return false;
    }
};