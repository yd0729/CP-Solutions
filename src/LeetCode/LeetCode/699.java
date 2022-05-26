import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> fallingSquares(int[][] ps) {
        List<Integer> ans = new ArrayList<>();
        for (int[] info : ps) {
            int x = info[0];
            int h = info[1];
            int cur = query(root, 0, N, x, x + h - 1);
            update(root, 0, N, x, x + h - 1, cur + h);
            ans.add(root.val);
        }
        return ans;
    }

    int N = (int) 1e9;

    class Node {
        // l 和 r 分别代表当前区间的左右子节点
        Node l, r;
        // val 代表当前区间的最大高度，add 为懒标记
        int val, add;
    }

    Node root = new Node();

    void update(Node node, int lc, int rc, int l, int r, int v) {
        if (l <= lc && rc <= r) {
            node.add = v;
            node.val = v;
            return;
        }

        pushdown(node);

        int mid = (lc + rc) >> 1;

        if (l <= mid) {
            update(node.l, lc, mid, l, r, v);
        }
        if (r > mid) {
            update(node.r, mid + 1, rc, l, r, v);
        }

        pushup(node);
    }

    int query(Node node, int lc, int rc, int l, int r) {
        if (l <= lc && rc <= r)
            return node.val;

        pushdown(node);

        int mid = (lc + rc) >> 1;
        int ans = 0;

        if (l <= mid) {
            ans = query(node.l, lc, mid, l, r);
        }
        if (r > mid) {
            ans = Math.max(ans, query(node.r, mid + 1, rc, l, r));
        }

        return ans;
    }

    void pushdown(Node node) {
        if (node.l == null)
            node.l = new Node();
        if (node.r == null)
            node.r = new Node();
        if (node.add == 0)
            return;

        node.l.add = node.add;
        node.r.add = node.add;
        node.l.val = node.add;
        node.r.val = node.add;

        node.add = 0;
    }

    void pushup(Node node) {
        node.val = Math.max(node.l.val, node.r.val);
    }
}