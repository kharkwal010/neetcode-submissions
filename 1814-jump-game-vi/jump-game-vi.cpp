class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<vector<int>> maxheap;
        maxheap.push({nums[0], 0});
        for(int i=1; i<nums.size(); i++){
            while(maxheap.top()[1]+k<i){
                maxheap.pop();
            }
            if(i==nums.size()-1) return maxheap.top()[0] + nums[i];
            maxheap.push({maxheap.top()[0] + nums[i], i});
        }
        return maxheap.top()[0];
        
    }
};