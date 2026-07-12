class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<int> maxheap;
        priority_queue<int> maxdel;
        priority_queue<int, vector<int>, greater<int>> minheap;
        priority_queue<int, vector<int>, greater<int>> mindel;
        int l = 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            maxheap.push(nums[i]);
            minheap.push(nums[i]);
            while(!maxdel.empty() && maxheap.top()==maxdel.top()){
                maxheap.pop();
                maxdel.pop();
            }
            while(!mindel.empty() && minheap.top()==mindel.top()){
                minheap.pop();
                mindel.pop();
            }
            if(maxheap.top()-minheap.top()>limit){
                maxdel.push(nums[l]);
                mindel.push(nums[l]);
                l++;
            }
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};