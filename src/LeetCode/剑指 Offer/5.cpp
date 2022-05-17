class Solution {
  public:
    string replaceSpace(string s) {
        vector<char> sb;
        sb.reserve(s.size() * 3);

        for (auto &e : s) {
            if (e == ' ') {
                sb.push_back('%');
                sb.push_back('2');
                sb.push_back('0');
            } else {
                sb.push_back(e);
            }
        }

        return string(sb.begin(), sb.end());
    }
};