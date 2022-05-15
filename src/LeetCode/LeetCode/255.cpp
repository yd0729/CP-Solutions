class Solution {
  public:
    bool verifyPreorder(vector<int> &preorder) {
        stack<int> stack;
        int min = INT_MIN;
        for (auto &e : preorder) {
            if (e < min) {
                return false;
            }
            while (!stack.empty() && e > stack.top()) {
                min = stack.top();
                stack.pop();
            }
            stack.push(e);
        }
        return true;
    }
};