class MedianFinder {
  public:
    priority_queue<int, vector<int>, less<int>> q_min; // 可能多存一个数
    priority_queue<int, vector<int>, greater<int>> q_max;

    MedianFinder() {}

    void addNum(int num) {
        if (q_min.empty() || num <= q_min.top()) {
            q_min.push(num);
            if (q_max.size() + 1 < q_min.size()) {
                q_max.push(q_min.top());
                q_min.pop();
            }
        } else {
            q_max.push(num);
            if (q_max.size() > q_min.size()) {
                q_min.push(q_max.top());
                q_max.pop();
            }
        }
    }

    double findMedian() {
        if (q_min.size() > q_max.size()) {
            return q_min.top();
        }
        return (q_min.top() + q_max.top()) / 2.0;
    }
};