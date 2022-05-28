class Solution {
  public:
    string minNumber(vector<int> &nums) {
        vector<string> str(nums.size());
        for (int i = 0; i < str.size(); i += 1) {
            str[i] = to_string(nums[i]);
        }

        sort(str.begin(), str.end(),
             [](auto &a, auto &b) { return a + b < b + a; });

        stringbuf sb;
        for (auto &e : str) {
            sb.sputn(e.c_str(), e.size());
        }
        return sb.str();
    }
};