class Solution {
public:
    unordered_map<string, long> memo;
    long dp(vector<int>& nums, int a, int n){
        if(n==0){
            return 0;
        }
        if(n<0){
            return INT_MAX;
        }
        string key = to_string(n)+"+"+ to_string(a);
        if(memo.find(key)!=memo.end()){
            return memo[key];
        }
        long ans = INT_MAX;
        for(int i=a; i<nums.size(); i++){
            ans = min(ans ,long(1 + dp(nums, i, n-nums[i])));
        }
        memo[key]=ans;
        return memo[key];
    }
    int numSquares(int n) {
       int i = 1;
       vector<int> nums;
       while(i*i<=n){
        nums.push_back(i*i);
        i++;
       } 

    //    long ans =  dp(nums, 0, n);
    //    if (ans>=INT_MAX){
    //     return 0;
    //    }
       return dp(nums, 0, n);
    }
};