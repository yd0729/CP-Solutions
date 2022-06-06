class MyCalendarThree {
public:
    MyCalendarThree() {}
    
    int book(int start, int end) {
        int ans = 0;
        int max_book = 0;

        cnt[start]++;
        cnt[end]--;
        
        for (auto &[_, freq] : cnt) {
            max_book += freq;
            ans = max(max_book, ans);
        }
        return ans;
    }
private:
    map<int, int> cnt;
};