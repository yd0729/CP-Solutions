class MedianFinder {
    multiset<int> data;
    multiset<int>::iterator mid; // 偶数时是后一个数

  public:
    MedianFinder() : mid(data.end()) {}

    void addNum(int num) {
        const int n = data.size();
        data.insert(num);

        if (n == 0)
            mid = data.begin();
        else if (num < *mid)
            mid = (n & 1 ? mid : prev(mid)); // 没插入之前的奇偶性
        else
            mid = (n & 1 ? next(mid) : mid);
    }

    double findMedian() {
        return (*mid + *prev(mid, data.size() % 2 == 0)) * 0.5;
    }
};