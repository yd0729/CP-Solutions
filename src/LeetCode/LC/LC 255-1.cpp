class MyStack {
public:
    MyStack() {}
    
    void push(int x) {
        q[in].push(x);
    }
    
    int pop() {
        move();
        
        int front = q[in].front();
        
        q[in].pop();
        in = 1 - in;
        
        return front;
    }
    
    int top() {
        move();
        return q[in].front();
    }
    
    bool empty() {
        return q[0].empty() and q[1].empty();
    }
private:
    int in = 1;  // push to this queue
    queue<int> q[2];
    
    void move() {
        while (q[in].size() > 1) {
            q[1 - in].push(q[in].front());
            q[in].pop();
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */