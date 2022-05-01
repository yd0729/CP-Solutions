#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void dfs(int i, vector<int> &count, const vector<vector<int>> &one_ids,
           int &cnt) {
    if (i == one_ids.size()) {
      ++cnt;
      return;
    }

    bool can_remove = true;
    for (auto e : one_ids[i]) {
      if (count[e] == 1) {
        can_remove = false;
      }
    }
    if (can_remove) {
      for (auto e : one_ids[i]) {
        --count[e];
      }

      dfs(i + 1, count, one_ids, cnt);

      for (auto e : one_ids[i]) {
        ++count[e];
      }
    }

    dfs(i + 1, count, one_ids, cnt);
  }
  int countMaxOrSubsets(vector<int> &nums) {
    int cnt = 0;
    auto one_ids = vector<vector<int>>(nums.size(), vector<int>());
    vector<int> count(20);

    for (int i = 0; i < nums.size(); i++) {
      int num = nums[i];

      for (int id = 0; num; num >>= 1, ++id) {
        if (num & 1) {
          one_ids[i].push_back(id);
          ++count[id];
        }
      }
    }

    for (int i = 0; i < nums.size(); i++) {
      sort(one_ids[i].begin(), one_ids[i].end(),
           [&](auto &a, auto &b) { return count[a] < count[b]; });
    }

    sort(one_ids.begin(), one_ids.end(), [&](auto &a, auto &b) {
      for (int j = 0; j < a.size() and j < b.size(); j++) {
        if (count[a[j]] != count[b[j]]) {
          return count[a[j]] < count[b[j]];
        }
      }
      return a.size() > b.size();
    });

    dfs(0, count, one_ids, cnt);

    return cnt;
  }
};