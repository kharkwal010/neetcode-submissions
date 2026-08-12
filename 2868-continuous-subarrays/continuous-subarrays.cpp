class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int l = 0;
        int r = 0;
        priority_queue<int, vector<int>, greater<int>> minheap;
        priority_queue<int> maxheap;
        priority_queue<int, vector<int>, greater<int>> mindel;
        priority_queue<int> maxdel;
        long long ans = 0;
        while(r<nums.size()){
            maxheap.push(nums[r]);
            minheap.push(nums[r]);
            while(l<nums.size() && (maxheap.top()-minheap.top())>2){
                maxdel.push(nums[l]);
                mindel.push(nums[l]);
                while(!maxdel.empty() && maxheap.top()==maxdel.top()){
                    // cout<<"maxheap "<<maxheap.top()<<endl;
                    maxheap.pop();
                    maxdel.pop();
                }
                while(!mindel.empty() && minheap.top()==mindel.top()){
                    // cout<<"minheap "<<minheap.top()<<endl;
                    minheap.pop();
                    mindel.pop();
                }
                l++;
            }
            r++;
            ans += (r-l);
        }
        return ans;
    }
};