class MyStack {
  public:
    MyStack() {}

    void push(int x) {
        int size = q.size();
        q.push(x);
        while (size--) {
            int t = q.front();
            q.pop();
            q.push(t);
        }
    }

    int pop() {
        int front = q.front();
        q.pop();
        return front;
    }

    int top() { return q.front(); }

    bool empty() { return q.empty(); }

  private:
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */