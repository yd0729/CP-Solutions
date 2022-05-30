class Solution {
  public:
    string discountPrices(string sentence, int discount) {
        string res;
        char val_str[30];
        int begin = 0, end, n = sentence.size();
        while ((end = sentence.find('$', begin)) != string::npos) {
            res += sentence.substr(begin, ++end - begin);
            begin = end;
            while (end < n and isdigit(sentence[end])) {
                end++;
            }
            if ((begin == 1 or sentence[begin - 2] == ' ') and begin < end and
                (end == n or sentence[end] == ' ')) {
                double val = stoll(sentence.substr(begin, end - begin)) *
                             (1 - discount / 100.0);
                sprintf(val_str, "%.2f", val);
                res += val_str;
            } else {
                res += sentence.substr(begin, end - begin);
            }
            begin = end;
        }
        if (begin != n) {
            res += sentence.substr(begin);
        }
        return res;
    }
};