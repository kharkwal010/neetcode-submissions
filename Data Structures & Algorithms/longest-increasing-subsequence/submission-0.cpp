class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> ans(nums.size(), 1);
        
        for (int i=nums.size()-1; i>=0; i--){
            int prevmax = nums[i];
            for( int j=i+1; j<nums.size(); j++){
                if(nums[j]>prevmax){
                    ans[i]=max(ans[j]+1, ans[i]);
                }
            }

        }
        return *max_element(ans.begin(), ans.end());
    }
};
