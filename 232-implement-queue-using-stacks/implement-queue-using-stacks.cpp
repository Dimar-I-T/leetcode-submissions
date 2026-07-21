class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        
    }

    int peekFirst() {
        int res = 0;
        while (!s1.empty()) {
            res = s1.top();
            s2.push(res);
            s1.pop();
        }

        return res;
    }

    void restore() {
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int res = peekFirst();
        s2.pop();
        restore();
        return res;
    }
    
    int peek() {
        int res = peekFirst();
        restore();
        return res;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */