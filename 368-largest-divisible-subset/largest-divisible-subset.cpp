class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int curr = 1;
        vector<int> dp(nums.size(), 1);
        for(int i=nums.size()-2; i>=0; i--){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[j]%nums[i]==0){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            curr = max(curr, dp[i]);
        }
        vector<int> ans;
        int prev = 1;
        for(int i=0; i<nums.size(); i++){
            if(dp[i]==curr && nums[i]%prev==0){
                ans.push_back(nums[i]);
                prev = nums[i];
                curr--;
                if(curr==0) break;
            }
        }
        return ans;

    }
};