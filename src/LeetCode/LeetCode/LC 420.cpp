class Solution {
  public:
    int strongPasswordChecker(string &s) {
        get_size(s);
        get_continuity(s);
        get_type(s);

        int step = 0;

        while (size > 20) {
            ++step;
            --size;

            for (int i = 0; i < 3; i++) {
                if (not con[i].empty()) {
                    int t = con[i].back();
                    con[i].pop_back();

                    if (--t > 2) {
                        con[t % 3].push_back(t);
                    }

                    break;
                }
            }
        }

        while (size < 6 or is_con()) {
            ++step;
            ++size;

            if (type < 3) {
                ++type;
            }

            for (int i = 0; i < 3; i++) {
                if (not con[i].empty()) {
                    int t = con[i].back();
                    con[i].pop_back();

                    t -= 3;

                    if (t > 2) {
                        con[t % 3].push_back(t);
                    }

                    break;
                }
            }
        }

        step += 3 - type;
        return step;
    }

  private:
    int size;
    int type;
    array<vector<int>, 3> con;

    inline void get_size(string &s) { size = s.size(); }

    inline void get_continuity(string &s) {
        for (int i = 0, j; i < s.size(); i = j) {
            j = i + 1;
            while (s[j] == s[i])
                ++j;
            if (j - i > 2) {
                con[(j - i) % 3].push_back(j - i);
            }
        }
    }

    inline void get_type(string &s) {
        bool up = false;
        bool low = false;
        bool digit = false;

        for (auto &c : s) {
            if (isupper(c)) {
                up = true;
            } else if (islower(c)) {
                low = true;
            } else if (isdigit(c)) {
                digit = true;
            }
        }

        type = up + low + digit;
    }

    inline bool is_con() {
        bool res = false;
        for (int i = 0; i < 3; i++) {
            if (not con[i].empty()) {
                res = true;
                break;
            }
        }
        return res;
    }
};