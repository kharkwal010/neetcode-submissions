class Solution {
public:
    int sumOfPower(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       long long prev = 0;
       long long sum = 0;
       long long ans = 0;
       int mod = 1e9+7;
       for(int i=0; i<nums.size(); i++){
            long long contri = ((prev + nums[i]) % mod
                    * ((1LL * nums[i] * nums[i]) % mod)) % mod;
            ans = (ans + contri)%mod;
            prev = (2*prev + nums[i])%mod;
       }
       return ans;
    }
};