class Solution {
  public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks,
                    int additionalRocks) {
        int n = capacity.size();
        for (int i = 0; i < n; i += 1) {
            capacity[i] -= rocks[i];
        }

        sort(begin(capacity), end(capacity));

        int i = 0;
        for (; i < n; i += 1) {
            if (additionalRocks < capacity[i]) {
                break;
            }
            additionalRocks -= capacity[i];
        }

        return i;
    }
};