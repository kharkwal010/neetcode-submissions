class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        priority_queue<int> maxheap;
        if(k==1) return 0;
        for(int i=0; i<weights.size()-1; i++){
            int val = weights[i] + weights[i+1];
            minheap.push(val);
            maxheap.push(val);
            if(minheap.size()>k-1){
                maxheap.pop();
                minheap.pop();
            }            
        }
        long long diff = 0;
        while(!maxheap.empty()){
            diff += minheap.top() - maxheap.top();
            maxheap.pop();
            minheap.pop();
        }
        return diff;
    }
};