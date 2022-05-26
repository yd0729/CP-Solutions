class Solution {
  public:
    vector<int> fallingSquares(vector<vector<int>> &positions) {
        int n = positions.size();

        vector<int> res(n);

        map<int, int> height;
        height[0] = 0; // 初始时从 0 开始的所有点的堆叠高度都是 0

        for (int i = 0; i < n; i++) {
            const int &square_h = positions[i][1];

            // 在区间 [l, r] 上堆叠
            const int &l = positions[i][0];
            const int r = l + square_h - 1;

            auto lb = height.upper_bound(l); // 第 1 个大于 l 的位置
            auto rb = height.upper_bound(r); // 第 1 个大于 r 的位置

            int r_height = prev(rb)->second;  // 最后一个不大于 r 的位置

            // 更新第 i 个掉落的方块的堆叠高度
            int h = 0;
            for (auto p = prev(lb); p != rb; p++) {  // 最后一个不大于 l 的位置
                h = max(h, p->second + square_h);
            }

            height.erase(lb, rb); // 清除 height 中位于 (l, r] 内的点
            height[l] = h; // 更新 l 的变化

            // 如果 r + 1 不在 height 中，更新 r + 1 的变化
            if (rb == height.end() || rb->first != r + 1) {
                height[r + 1] = r_height;
            }

            res[i] = i > 0 ? max(res[i - 1], h) : h;
        }

        return res;
    }
};