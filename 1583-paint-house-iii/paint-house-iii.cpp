class Solution {
public:
    vector<vector<vector<int>>> memo;
    long long costing(vector<int>& houses, vector<vector<int>>& cost, int target, int prev, int i, int n){
        if(target==0) return INT_MAX;
        if(i==houses.size()){
            if(target==1) return 0;
            else return INT_MAX;
        }
        if(memo[i][prev][target]!=-1) return memo[i][prev][target];
        long long ans = INT_MAX;
        long long sum = 0;
        if(houses[i]!=0){
            if(!(prev==n || houses[i]-1==prev)) target--;
            ans = min(ans, sum + costing(houses, cost, target, houses[i]-1, i+1, n));
            if(!(prev==n || houses[i]-1==prev)) target++;
        }
        else{
            for(int j=0; j<cost[0].size(); j++){
                if(!(prev==n || prev==j)){
                    target--;
                    ans = min(ans, sum + cost[i][j] + costing(houses, cost, target, j, i+1, n));
                    target++;
                }
                else{
                    ans = min(ans, sum + cost[i][j] + costing(houses, cost, target, j, i+1, n));
                }
            }
        }
        memo[i][prev][target] = ans;
        return ans;       

    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memo.resize(m, vector<vector<int>>(n+1, vector<int>(target+1, -1)));
        int ans = costing(houses, cost, target, n, 0, n);
        return (ans==INT_MAX) ? -1 : ans;
    }
};