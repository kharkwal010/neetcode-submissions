class FreqStack {
public:
    unordered_map<int, int> count;
    int i=0;
    priority_queue<vector<int>> maxheap;
    FreqStack() {
        
    }
    
    void push(int val) {
        count[val]++;
        maxheap.push({count[val],i, val});
        i++;
    }
    
    int pop() {
        auto top = maxheap.top();
        maxheap.pop();
        count[top[2]]--;
        return top[2];
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */