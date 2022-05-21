class Solution {
  public:
    int translateNum(int num) {
        if (num == 0) {
            return 1;
        }
        int x = num % 10;
        int res = translateNum(num /= 10);
        if ((num % 10 == 2 and x <= 5) or num % 10 == 1) {
            res += translateNum(num / 10);
        }
        return res;
    }
};