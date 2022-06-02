class Solution {
  public:
    bool verifyPostorder(vector<int> &postorder) {
        return verifyPostorder(postorder, 0, postorder.size(), INT_MIN,
                               INT_MAX);
    }

  private:
    bool verifyPostorder(vector<int> &postorder, int start, int len, int min,
                         int max) {
        if (len == 0) {
            return true;
        }

        int root_val = postorder[start + len - 1];
        if (root_val > max or root_val < min) {  // 检查 root 的大小
            return false;
        }

        int pivot = start;
        while (postorder[pivot] < root_val) {
            pivot += 1;
        }

        int l_len = pivot - start;
        int r_len = len - l_len - 1;

        return verifyPostorder(postorder, start, l_len, min, root_val - 1) and
               verifyPostorder(postorder, pivot, r_len, root_val + 1, max);
    }
};