class Solution {
  public:
    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        priority_queue<int> pq;

        for (auto &e : arr) {
            pq.push(e);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> res;
        while (not pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};