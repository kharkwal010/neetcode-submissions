class Solution {
public:
 // how to apply memo here
    vector<vector<vector<int>>> memo;
    int mod = 1e9+7;
    vector<int> pmemo;
    int power(int n){
        if(n==0) return 1;
        if(n==1) return 2;
        if(pmemo[n]!=-1) return pmemo[n];
        long long ans = 1;
        int a = n/2;
        ans = ((ans * power(a))%mod * power(n-a))%mod;
        return pmemo[n] = ans;

    }
    int solve(vector<int>& nums, int k, int sum, int cnt, int i){
        if(sum>k) return 0;
        if(sum==k) return power(nums.size()-cnt);
        if(i==nums.size()) return 0;

        if(memo[i][sum][cnt]!=-1) return memo[i][sum][cnt];
        long long ans = 0;
        ans = (ans + solve(nums, k, sum, cnt, i+1))%mod;
        ans = (ans + solve(nums, k, sum+nums[i], cnt+1, i+1))%mod;
        return memo[i][sum][cnt] = ans;


    }
    int sumOfPower(vector<int>& nums, int k) {
        int n = nums.size();
        pmemo.resize(n+1, -1);
        memo.resize(n, vector<vector<int>>(k, vector<int>(n, -1)));
        return solve(nums, k, 0, 0, 0);
    }
};