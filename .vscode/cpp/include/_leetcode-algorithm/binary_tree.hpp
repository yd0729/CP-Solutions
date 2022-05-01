#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

vector<int> in_trav(TreeNode *r) {
    vector<int> res;
    stack<TreeNode *> stk;

    if (r) {
        stk.push(r);
    }

    while (not stk.empty()) {
        while (stk.top()->left) {
            stk.push(stk.top()->left);
        }
        while (not stk.empty()) {
            auto t = stk.top();
            stk.pop();

            res.push_back(t->val);

            if (t->right) {
                stk.push(t->right);
                break;
            }
        }
    }

    return res;
}

vector<int> in_trav_r(TreeNode *r) {
    vector<int> res;

    function<void(TreeNode *)> _in_trav = [&](TreeNode *r) {
        if (r == nullptr) {
            return;
        }
        _in_trav(r->left);
        res.push_back(r->val);
        _in_trav(r->right);
    };

    _in_trav(r);

    return res;
}