class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        int mod= 1e9+7;
        long long sum = 0;
        
        sort(nums.begin(), nums.end());
        long long ans = 0;

        for(int i=0; i<nums.size(); i++){
            long long contri = (sum + nums[i])%mod;
            long long curr = ((long long)nums[i]*nums[i])%mod;
            // cout<<contri<<" "<<curr<<endl;
            ans = (ans + contri * curr)%mod;
            sum = (2*sum + nums[i])%mod;           
            
        }
        return ans;
    }
};