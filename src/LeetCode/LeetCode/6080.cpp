class Solution {
  public:
    int totalSteps(vector<int> &nums) {
        int n = nums.size();
        list<list<int>> lq;

        lq.emplace_back();
        lq.back().push_back(nums[0]);

        for (int i = 1; i < n; i += 1) {
            if (nums[i] < nums[i - 1]) {
                lq.emplace_back();
            }
            lq.back().push_back(nums[i]);
        }

        vector<bool> del(lq.size());
        int res = 0;

        for (;; res += 1) {
            int idx = 1;
            bool ok = true;
            fill(begin(del), end(del), false);

            for (auto i = next(lq.begin()); i != lq.end(); idx++, i++) {
                if (i->front() < prev(i)->back()) {
                    del[idx] = true;
                    ok = false;
                }
            }

            if (ok) {
                return res;
            }

            idx = 1;
            for (auto i = next(lq.begin()); i != lq.end(); idx++) {
                if (del[idx]) {
                    i->pop_front();
                }
                if (i->empty()) {
                    i = lq.erase(i);
                } else {
                    i++;
                }
            }
        }
    }
};