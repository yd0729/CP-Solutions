#include "leetcode.hpp" 
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {

        vector<int> idx(256, -1); // 字符->最后出现的位置

        int res = 0;
        int start = 0; // 当前子串的开始位置

        for (int i = 0, size = (int)s.size(); i < size; ++i) {
            if (idx[s[i]] >= start) {  // 当前字符与之前字符重复
                start = idx[s[i]] + 1; // 从重复的下一个开始
            }

            // 当前的无重复字符串：[start, i]
            res = max(res, i - start + 1);
            idx[s[i]] = i;
        }

        return res;
    }
};