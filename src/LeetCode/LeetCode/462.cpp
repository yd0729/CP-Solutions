class Solution {
  public:
    int minMoves2(vector<int> &nums) {
        int n = nums.size();
        int x = quickSelect(nums, 0, n - 1, n / 2);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += abs(nums[i] - x);
        }
        return res;
    }

  private:
    int quickSelect(vector<int> &a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q == index) {
            return a[q];
        } else {
            return q < index ? quickSelect(a, q + 1, r, index)
                             : quickSelect(a, l, q - 1, index);
        }
    }

    int randomPartition(vector<int> &a, int l, int r) {
        // random_device ：使用硬件熵源的非确定随机数生成器
        static mt19937 rand_engine(random_device{}()); // 32 位梅森缠绕器
        uniform_int_distribution<size_t> uid(l, r);    // 均匀分布
        swap(a[uid(rand_engine)], a[r]);               // 把 pivot 放到最后
        return partition(a, l, r);
    }

    int partition(vector<int> &a, int l, int r) {
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (a[j] <= x) {        // 和 pivot 比较
                swap(a[++i], a[j]); // < pivot 的交换到前面
            }
        }
        swap(a[i + 1], a[r]); // 把 pivot 放到正确的位置
        return i + 1;
    }
};