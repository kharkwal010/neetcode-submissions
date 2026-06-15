class FreqStack {
public:
    unordered_map<int, int> count;
    vector<vector<int>> arr;
    FreqStack() {
        
    }    
    void push(int val) {
        count[val]++;
        if(arr.size()<count[val]) arr.push_back({});
        arr[count[val]-1].push_back(val);
    }
    
    int pop() {
        vector<int>& a = arr.back();
        int ans = a.back();
        a.pop_back();
        if(a.size()==0) arr.pop_back();
        count[ans]--;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */