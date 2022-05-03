class Solution {
  public:
    vector<string> reorderLogFiles(vector<string> &logs) {
        stable_sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            int pa = word_pos(a);
            int pb = word_pos(b);

            int ta = isdigit(a[pa]);
            int tb = isdigit(b[pb]);

            if (ta != tb) {
                return ta < tb;
            } else if (ta == 0) {
                int cmp = strcmp(a.c_str() + pa, b.c_str() + pb);
                if (cmp == 0) {
                    return strncmp(a.c_str(), b.c_str(), min(pa, pb)) < 0;
                } else {
                    return cmp < 0;
                }
            } else {
                return false;
            }
        });
        return logs;
    }

  private:
    static int word_pos(const string &s) { return s.find(" ") + 1; }
};