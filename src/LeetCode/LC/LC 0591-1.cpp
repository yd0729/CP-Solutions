class Solution {
  public:
    bool isValid(string code) {
        this->code = move(code);
        cur = 0;

        if (not is_closed_tag(this->code.size())) {
            return false;
        }
        return cur == this->code.size();
    }

  private:
    string code;
    int cur;

    bool is_closed_tag(int r) {
        if (r - cur < 7) { // 最小： <A></A>
            return false;
        }

        if (code[cur++] != '<') {
            return false;
        }

        string tag_name;
        for (; cur < r and code[cur] != '>'; ++cur) {
            if (code[cur] < 'A' or code[cur] > 'Z') {
                return false;
            }

            tag_name += code[cur];

            if (tag_name.size() > 9) {
                return false;
            }
        }
        if (cur == r or tag_name.empty()) {
            return false;
        }
        cur += 1;

        if (not is_tag_content(r)) {
            return false;
        }

        if (code.find("</" + tag_name + ">", cur) != cur) {
            return false;
        }
        cur += tag_name.size() + 3;

        return true;
    }

    bool is_tag_content(int r) {
        while (cur < r) {
            if (code[cur] == '<') {
                if (cur + 1 < r and code[cur + 1] == '!') {
                    if (not is_cdata(r)) {
                        return false;
                    }
                } else if (cur + 1 < r and code[cur + 1] == '/') {
                    return true;
                } else if (not is_closed_tag(r)) {
                    return false;
                }
            } else {
                cur += 1;
            }
        }
        return false;
    }

    bool is_cdata(int r) {
        if (r - cur < 12) { // 最小：<![CDATA[]]>
            return false;
        }

        cur += 2;
        if (code.find("[CDATA[", cur) != cur) {
            return false;
        }
        cur += 7;

        if ((cur = code.find("]]>", cur)) == string::npos or cur + 3 > r) {
            return false;
        }
        cur += 3;

        return true;
    }
};