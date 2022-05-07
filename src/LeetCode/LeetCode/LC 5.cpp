class Solution {
  public:
    string longestPalindrome(string &ss) {
        s = move(ss);

        int start = 0, end = -1;             // 最长回文串 [start, end)
        vector<int> arm_len(ppos(s.size())); // 臂长不包括中心点
        int right = -1, j = -1; // 最右侧的位置、对应的中心

        for (int i = 0; i < ppos(s.size()); ++i) {
            // 利用 j 计算当前位置臂长
            int &cur_arm_len = arm_len[i];
            if (right >= i) {
                int i_sym = j * 2 - i; // i 关于 j 的对称点
                int min_arm_len = min(arm_len[i_sym], right - i);
                cur_arm_len = expand(i - min_arm_len, i + min_arm_len);
            } else {
                cur_arm_len = expand(i, i);
            }
            // 更新最右臂
            if (i + cur_arm_len > right) {
                j = i;
                right = i + cur_arm_len;
            }
            // 更新答案
            if (cur_arm_len * 2 + 1 > end - start) {
                start = i - cur_arm_len;
                end = i + cur_arm_len;
            }
        }

        return s.substr(pos(start), pos(end) - pos(start));
    }

  private:
    string s;

    inline int expand(int left, int right) {
        while (left >= 0 && right < ppos(s.size()) &&
               (left % 2 + right % 2 == 0 or s[pos(left)] == s[pos(right)])) {
            --left;
            ++right;
        }
        return (right - left - 2) / 2;
    }

    inline int ppos(int pos) { return pos * 2 + 1; }

    inline int pos(int ppos) { // 将位置映射回原字符串
        return ppos / 2;
    }
};