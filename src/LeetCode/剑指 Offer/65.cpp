class Solution {
  public:
    int add(int a, int b) {
        // 当进位为 0 时跳出
        while (b != 0) {
            // 进位，unsigned 防止移位后 INT_MIN
            auto c = (unsigned int)(a & b) << 1;
            // 非进位和
            a ^= b;
            b = c;
        }
        return a;
    }
};