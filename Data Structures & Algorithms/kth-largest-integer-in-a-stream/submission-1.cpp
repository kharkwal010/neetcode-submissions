class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minheap;
    int number;
    KthLargest(int k, vector<int>& nums) {
        number = k;
        for(int i=0; i<nums.size(); i++){
            minheap.push(nums[i]);
            if(minheap.size()>k){
                minheap.pop();
            }
        }
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size()>number){
            minheap.pop();
        }
        return minheap.top();
    }
};
