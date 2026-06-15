class FreqStack {
public:
    unordered_map<int, int> count;
    vector<vector<int>> terms;

    FreqStack() {
        
    }
    
    void push(int val) {
        count[val]++;
        if(count[val]>terms.size()){
            terms.push_back({});
        }
        terms[count[val]-1].push_back(val);
        return;
    }
    
    int pop() {
        int ans = terms.back().back();
        terms.back().pop_back();
        if(terms.back().size()==0) terms.pop_back();
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