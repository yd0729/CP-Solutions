/* 307.cpp
 *
 * Author: Author
 * Created: Mon Apr 04 2022
 */

#include <bits/stdc++.h>

using namespace std;

#ifdef YD_DEBUG
#include <chrono>
#include <cstdio>
#define debug(x) cout << #x << " = " << (x) << endl
#else
#define debug(x)
static int speedup = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();
#endif

class NumArray {
 public:
  NumArray(vector<int>& nums) {}

  void update(int index, int val) {}

  int sumRange(int left, int right) {}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */