class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<nums.size()-3; i++){
            long long t = target - nums[i];
            for(int j=i+1;j<nums.size()-2; j++){
                long long tar = t-nums[j];
                int l = j+1;
                int r = nums.size()-1;
                while(l<r){
                    long long sum = nums[l] + nums[r];
                    if(sum<tar) l++;
                    else if(sum>tar) r--;
                    else{
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while(l<r && nums[l+1]==nums[l]) l++;
                        while(l<r && nums[r-1] == nums[r]) r--;
                        l++;
                        r--;
                    }
                }
                while(j<nums.size()-2 && nums[j]==nums[j+1]) j++;
            }
            while(i<nums.size()-3 && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};