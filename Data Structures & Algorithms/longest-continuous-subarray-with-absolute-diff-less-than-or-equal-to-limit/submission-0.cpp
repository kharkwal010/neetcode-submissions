class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<int> maxheap;
        priority_queue<int> maxdel;
        priority_queue<int, vector<int>, greater<int>> minheap;
        priority_queue<int, vector<int>, greater<int>> mindel;
        maxheap.push(nums[0]);
        minheap.push(nums[0]);
        int r = 1;
        int l = 0;
        int ans = 1;
        while(r<nums.size()){
            if((maxheap.empty() || maxheap.top()-nums[r]<=limit) && (minheap.empty() || nums[r]-minheap.top()<=limit)){                
                maxheap.push(nums[r]);
                minheap.push(nums[r]);
                ans = max(ans, r-l+1);
                r++;
                continue;
            }
            maxdel.push(nums[l]);
            mindel.push(nums[l]);
            l++;
            while(!maxdel.empty() && maxheap.top()==maxdel.top()){
                maxdel.pop();
                maxheap.pop();
            }
            while(!mindel.empty() && minheap.top()==mindel.top()){
                mindel.pop();
                minheap.pop();
            }

        }
        return ans;
    }
};