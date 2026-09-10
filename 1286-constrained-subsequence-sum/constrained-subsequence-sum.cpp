class Solution {
public:    
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxheap;
        int ans = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            while(!maxheap.empty() && i-maxheap.top().second>k) maxheap.pop();
            int prev = (maxheap.empty()) ? 0 : maxheap.top().first;
            int curr = prev + nums[i];
            ans = max(ans, curr);
            if(curr>0) maxheap.push({curr, i});
        }
        return ans;
    }
};