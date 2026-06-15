class Solution {
public:
    unordered_map<int, int> memo;
   int stair(int n){
    if(n==0 || n==1){
        return 1;
    }
    
    if(memo.find(n)!=memo.end()){
        return memo[n];
    }
    int ans = stair(n-1) + stair(n-2);
    memo[n]=ans;
    return ans;

   }
    int climbStairs(int n) {
       int ans = stair(n);
       return ans;
    }
};
