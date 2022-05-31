class Solution {
  public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < (1 << k) + k - 1) {
            return false;
        }

        // 要转换的字符串 存储已处理字符数的整数的地址 数的底
        int num = stoi(s.substr(0, k), nullptr, 2);
        unordered_set<int> exists = {num};

        for (int i = 1; i + k <= s.size(); ++i) {
            num = (num - ((s[i - 1] - '0') << (k - 1))) * 2 +
                  (s[i + k - 1] - '0');
            exists.insert(num);
        }
        return exists.size() == (1 << k);
    }
};