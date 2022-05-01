/* LeetCode 0045.cpp
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

class Solution {
 public:
  int jump(vector<int> &nums) {
    int cnt = 0;
    for (int i = 0, pos = 0, next_pos = 0, hi = nums.size() - 1; pos < hi;
         ++i) {
      next_pos = max(nums[i] + i, next_pos);
      if (i == pos) {
        ++cnt;
        pos = next_pos;
      }
    }
    return cnt;
  }
};

void trimLeftTrailingSpaces(string &input) {
  input.erase(input.begin(), find_if(input.begin(), input.end(),
                                     [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input) {
  input.erase(
      find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); })
          .base(),
      input.end());
}

vector<int> stringToIntegerVector(string input) {
  vector<int> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  stringstream ss;
  ss.str(input);
  string item;
  char delim = ',';
  while (getline(ss, item, delim)) {
    output.push_back(stoi(item));
  }
  return output;
}

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> nums = stringToIntegerVector(line);

    int ret = Solution().jump(nums);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}