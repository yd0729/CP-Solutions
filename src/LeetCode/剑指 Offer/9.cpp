class CQueue {
  public:
    CQueue() {}

    void appendTail(int value) { in.push(value); }

    int deleteHead() {
        if (out.empty()) {
            if (in.empty()) {
                return -1;
            }
            move();
        }

        int head = out.top();
        out.pop();

        return head;
    }

  private:
    stack<int> in, out;

    void move() {
        while (not in.empty()) {
            out.push(in.top());
            in.pop();
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */