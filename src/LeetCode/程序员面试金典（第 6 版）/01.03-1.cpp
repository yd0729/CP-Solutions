class Solution {
  public:
    string replaceSpaces(string S, int length) {
        int cur = 0;
        vector<char> sb;
        for (auto &e : S) {
            if (cur >= length) {
                break;
            }
            if (e == ' ') {
                sb.push_back('%');
                sb.push_back('2');
                sb.push_back('0');
            } else {
                sb.push_back(e);
            }
            cur += 1;
        }
        return string(sb.begin(), sb.end());
    }
};