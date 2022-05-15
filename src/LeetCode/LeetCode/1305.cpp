class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        auto in1 = in_trav(root1);
        auto in2 = in_trav(root2);

        vector<int> res(in1.size() + in2.size());
        merge(begin(in1), end(in1), begin(in2), end(in2), begin(res));

        return res;
    }
};