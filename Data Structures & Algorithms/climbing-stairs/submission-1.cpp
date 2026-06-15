class Solution {
public:
    unordered_map<int, int> memo;
    int stair(int n){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(memo.find(n)!=memo.end()){
            return memo[n];
        }
        memo[n]=stair(n-1)+stair(n-2);
        return memo[n];
    }
    int climbStairs(int n) {
       int ans = stair(n);
       return ans;
    }
};
