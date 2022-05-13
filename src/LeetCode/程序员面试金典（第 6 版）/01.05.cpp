class Solution {
  public:
    bool oneEditAway(string &first, string &second) {
        int m = first.size(), n = second.size();
        if (n - m == 1) {
            return oneInsert(first, second);
        } else if (m - n == 1) {
            return oneInsert(second, first);
        } else if (m == n) {
            bool found_diff = false;
            for (int i = 0; i < m; i++) {
                if (first[i] != second[i]) {
                    if (!found_diff) {
                        found_diff = true;
                    } else {
                        return false;
                    }
                }
            }
            return true;
        } else {
            return false;
        }
    }

  private:
    bool oneInsert(string &shorter, string &longer) {
        int len1 = shorter.size(), len2 = longer.size();
        int index1 = 0, index2 = 0;
        while (index1 < len1 && index2 < len2) {
            if (shorter[index1] == longer[index2]) {
                index1++;
            }
            index2++;
            if (index2 - index1 > 1) {
                return false;
            }
        }
        return true;
    }
};