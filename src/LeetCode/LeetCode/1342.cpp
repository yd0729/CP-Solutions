class Solution {
  public:
    int numberOfSteps(int num) {
        int cnt = 0;
        while (num) {
            if (num % 2) {
                num -= 1;
            } else {
                num /= 2;
            }
            cnt += 1;
        }
        return cnt;
    }
};