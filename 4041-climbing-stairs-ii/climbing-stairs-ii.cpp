class Solution {
public:
    vector<int> memo;
    int jump(vector<int>& costs, int i){
        if(i==costs.size()-1) return 0;
        if(memo[i]!=-1) return memo[i];
        int maxi = min((int)costs.size(), i+4);
        int ans = INT_MAX;
        for(int j=i+1; j<maxi; j++){
            ans = min(ans, costs[j] + (j-i)*(j-i) + jump(costs, j));
        }
        return memo[i] = ans;

    }
    int climbStairs(int n, vector<int>& costs) {
        memo.resize(n+1, -1);
        int ans = INT_MAX;
        int mini = min(n, 3);
        for(int i=0; i<mini; i++){
            ans = min(ans, (i+1)*(i+1) + costs[i] + jump(costs, i));
        }   
        return ans;     
    }
};