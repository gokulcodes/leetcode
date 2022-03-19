class FreqStack {
public:
    map<int, int> freq;
    map<int, stack<int>> group;
    int mxFreq = 0;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        if(freq[val] > mxFreq)
            mxFreq = freq[val];
        
        group[freq[val]].push(val);
    }
    
    int pop() {
        int x = group[mxFreq].top();
        group[mxFreq].pop();
        freq[x]--;
        if(group[mxFreq].size() == 0)
            mxFreq--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */