class MyCalendarThree {
  public:
    MyCalendarThree() {}

    void update(int start, int end, int l, int r, int i) {
        if (r < start || end < l) {
            return;
        }
        if (start <= l && r <= end) { // [start [l r] end]
            tree[i].cnt += 1;
            tree[i].max_book += 1;
        } else {
            int mid = (l + r) >> 1;

            update(start, end, l, mid, 2 * i);
            update(start, end, mid + 1, r, 2 * i + 1);

            auto &l = tree[2 * i];
            auto &r = tree[2 * i + 1];
            tree[i].max_book = tree[i].cnt + max(l.max_book, r.max_book);
        }
    }

    int book(int start, int end) {
        update(start, end - 1, 0, 1e9, 1);
        return tree[1].max_book;
    }

  private:
    struct record {
        int max_book; // 当前层的最大预定次数
        int cnt;      // 区间累加次数
    };

    unordered_map<int, record> tree;
};