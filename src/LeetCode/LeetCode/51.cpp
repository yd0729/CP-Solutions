class Solution {
  public:
    vector<vector<string>> solveNQueens(int n) {
        // 第 i 行是否有皇后
        vector<bool> used(n);
        // 当前排列（第 i 列皇后在第 permutation[i] 行上）
        vector<int> permutation(n);

        vector<vector<string>> ans;
        vector<string> blank(n, string(n, '.'));

        function<void(int)> n_queens;
        n_queens = [&](int idx) {
            if (idx == n) { // 找到一个合法方案
                ans.push_back(blank);
                for (int i = 0; i < n; ++i)
                    ans.back()[permutation[i]][i] = 'Q';
            }

            for (int x = 0; x < n; ++x) { // 第 x 行
                if (not used[x]) {
                    // 检查斜向是否有冲突
                    bool check_diagonal = true;
                    for (int pre = 0; pre < idx; ++pre) {
                        // 与之前的皇后在一条对角线上
                        if (abs(idx - pre) == abs(x - permutation[pre])) {
                            check_diagonal = false;
                            break;
                        }
                    }
                    if (check_diagonal) {
                        permutation[idx] = x;
                        used[x] = true;
                        n_queens(idx + 1);
                        used[x] = false;
                    }
                }
            }
        };

        n_queens(0);
        return ans;
    }
};