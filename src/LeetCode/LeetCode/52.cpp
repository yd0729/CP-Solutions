class Solution {
  public:
    int totalNQueens(const int n) {
        vector<bool> used(n);       // 第i行是否有皇后
        vector<int> permutation(n); // 当前排列

        int cnt = 0;

        function<void(int)> n_queens = [&](int index) -> void {
            if (index == n) { // 找到一个合法方案
                cnt += 1;
            }

            for (int x = 0; x < n; ++x) { // 第x行
                if (not used[x]) {
                    bool flag = true; // 表示当前皇后不会和之前皇后冲突
                    for (int pre = 0; pre < index; ++pre) {
                        // 与之前的皇后在一条对角线上
                        if (abs(index - pre) == abs(x - permutation[pre])) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        permutation[index] = x;
                        used[x] = true;
                        n_queens(index + 1);
                        used[x] = false;
                    }
                }
            }
        };

        n_queens(0);

        return cnt;
    }
};