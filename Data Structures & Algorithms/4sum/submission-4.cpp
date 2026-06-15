class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        long long t1, t2;
        int l, r;
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            t1 = (long long)target - nums[i];
            for(int j=i+1; j<nums.size(); j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                t2 = t1 - nums[j];
                l = j+1;
                r = nums.size()-1;
                while(l<r){
                    if(l>j+1 && nums[l]==nums[l-1]){
                        l++;
                        continue;
                    }
                    long long sum = nums[l]+nums[r];
                    if(sum==t2){
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                    }
                    else if(sum>t2) r--;
                    else l++;
                }
            }
        }
        return ans;
    }
};