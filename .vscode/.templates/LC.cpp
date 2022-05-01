#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *_left, TreeNode *_right)
        : val(x), left(_left), right(_right) {}
};

namespace algorithm {
vector<int> in_trav(TreeNode *r) {
    vector<int> res;
    vector<TreeNode *> v;
    v.reserve(6000);
    stack stk{v};

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
} // namespace algorithm

using namespace algorithm;

class Solution {
  public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        auto in1 = in_trav(root1);
        auto in2 = in_trav(root2);

        vector<int> res(in1.size() + in2.size());
        merge(begin(in1), end(in1), begin(in2), end(in2), begin(res));

        return res;
    }
};
