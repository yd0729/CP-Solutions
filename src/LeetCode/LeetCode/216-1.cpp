class Solution {
  public:
    vector<vector<int>> combinationSum3(int k, int n) {
        res.clear();

        combinationSum3(k, n, 1);

        return res;
    }

  private:
    vector<int> backtrace;
    vector<vector<int>> res;

    void combinationSum3(int k, int n, int mi) {
        if (k == 0 or n <= 0) {
            if (k == 0 and n == 0) {
                res.push_back(backtrace);
            }
            return;
        }

        for (int i = mi; i <= 9; ++i) {
            backtrace.push_back(i);
            combinationSum3(k - 1, n - i, i + 1);
            backtrace.pop_back();
        }
    }
};