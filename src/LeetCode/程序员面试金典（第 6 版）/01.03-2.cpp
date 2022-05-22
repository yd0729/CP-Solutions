class Solution {
  public:
    string replaceSpaces(string str, int length) {
        int cur = str.size() - 1;
        for (int i = length - 1; i >= 0; i--) {
            if (str[i] == ' ') {
                str[cur] = '0';
                str[cur - 1] = '2';
                str[cur - 2] = '%';
                cur -= 3;
            } else {
                str[cur] = str[i];
                cur--;
            }
        }
        return str.substr(cur + 1);
    }
};