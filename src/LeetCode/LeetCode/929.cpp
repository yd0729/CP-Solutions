class Solution {
  public:
    int numUniqueEmails(vector<string> &emails) {
        unordered_set<string> valid;
        for (auto &email : emails) {
            auto at = find(email.begin(), email.end(), '@');
            auto it = remove(email.begin(), at, '.');  // 把 . 移到 @ 之前
            email.erase(it, at);

            at = find(email.begin(), email.end(), '@');  // 重新找
            auto plus = find(email.begin(), at, '+');
            email.erase(plus, at);

            valid.insert(email);
        }
        return valid.size();
    }
};