class FreqStack {
public:
    int maks = 0;
    unordered_map<int, int> valFreq;
    unordered_map<int, stack<int>> freqVal;
    FreqStack() {
    }
    
    void push(int val) {
        int prevFreq = valFreq[val];
        int nextFreq = prevFreq + 1;
        freqVal[nextFreq].push(val);
        valFreq[val]++;
        maks = max(maks, nextFreq);
    }
    
    int pop() {
        bool valid = emptyCheck();
        if (!valid) {
            return -1;
        }
        
        int res = freqVal[maks].top();
        freqVal[maks].pop();
        int prevFreq = valFreq[res];
        int nextFreq = prevFreq - 1;
        valFreq[res]--;
        emptyCheck();
        return res;
    }

    bool emptyCheck() {
        bool valid = 1;
        while (freqVal[maks].empty()) {
            if (maks <= 0) {
                valid = 0;
                break;
            }

            maks--;
        }

        return valid;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */