class RecentCounter {
  public:
    RecentCounter() {}

    int ping(int t) {
        p.push(t);
        while (not p.empty() and p.front() < t - 3000) {
            p.pop();
        }
        return p.size();
    }

  private:
    queue<int> p;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */