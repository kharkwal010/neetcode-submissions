class KthLargest {
public:
    int terms;
    priority_queue<int, vector<int>, greater<int>> minheap;
    KthLargest(int k, vector<int>& nums) {
        terms = k;
        for(int n: nums){
            minheap.push(n);
            if(minheap.size()>k) minheap.pop();
        }
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size() > terms) minheap.pop();
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */