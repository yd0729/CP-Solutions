class Solution {
  public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() or matrix[0].empty()) {
            return false;
        }

        int n = matrix.size();
        int m = matrix[0].size();

        int i = 0, j = m - 1;
        while (i < n and j >= 0) {
            int &num = matrix[i][j];

            if (num == target) {
                return true;
            } else if (num < target) {
                i += 1;
            } else {
                j -= 1;
            }
        }

        return false;
    }
};