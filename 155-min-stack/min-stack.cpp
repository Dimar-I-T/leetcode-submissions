class MinStack {
public:
    // dimar's solution
    int s[30000][2];
    int i = 0;
    MinStack() {
        
    }
    
    void push(int val) {
        s[i][0] = val;
        s[i][1] = (i == 0) ? val : min(s[i - 1][1], val);
        i++;
    }
    
    void pop() {
        i--;
    }
    
    int top() {
        return s[i - 1][0];
    }
    
    int getMin() {
        return s[i - 1][1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */