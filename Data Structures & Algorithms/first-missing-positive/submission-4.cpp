class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=0) nums[i] = INT_MAX;
        }
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(abs(nums[i])>n) continue;
            else if(nums[abs(nums[i])-1]>0) nums[abs(nums[i])-1]*=-1;
        }

        for(int i=0; i<n; i++){
            if(nums[i]>0) return i+1;
        }
        return n+1;
    }
};