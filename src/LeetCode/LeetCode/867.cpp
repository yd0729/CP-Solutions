class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> res(n, vector<int>(m));

        for (int i = 0; i < m; i += 1) {
            for (int j = 0; j < n; j += 1) {
                res[j][i] = matrix[i][j];
            }
        }

        return res;
    }
};