class Solution {
public:    
    int constrainedSubsetSum(vector<int>& nums, int k) {
       priority_queue<pair<int, int>> maxheap;
       int ans = nums[0];
       maxheap.push({nums[0], 0});
       for(int i=1; i<nums.size(); i++){
            while(i-maxheap.top().second>k) maxheap.pop();
            int curr = max(maxheap.top().first, 0);
            ans = max(ans, curr + nums[i]);
            maxheap.push({curr + nums[i], i});
       }
       return ans;
    }
};