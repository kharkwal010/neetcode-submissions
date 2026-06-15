class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size()-1;
        int count = 0;
        int mod = 1e9+7;
        vector<int> power(nums.size(), 1);
        for(int i=1; i<nums.size(); i++){
            power[i] = (power[i-1]*2)%mod;
        }
        while(l<=r){
            if(nums[l]+nums[r]>target) r--;
            else{
                count = (count + power[r-l]) % mod;
                l++;
            }
        }
        return count ; 
    }
};