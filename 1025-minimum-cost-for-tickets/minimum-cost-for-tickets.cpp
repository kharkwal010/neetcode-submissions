class Solution {
public:
    vector<int> memo;
    int cost(vector<int>& days, vector<int>& costs, int i){
        if(i==days.size()) return 0;
        if(memo[i]!=-1) return memo[i];
        int ans = INT_MAX;
        ans = min(ans, costs[0] + cost(days, costs, i+1));
        int nxt = days[i] + 6;
        int j = i;
        while(j<days.size() && days[j]<=nxt) j++;
        ans = min(ans, costs[1] + cost(days, costs, j));
        nxt = days[i] + 29;
        while(j<days.size() && days[j]<=nxt) j++;
        ans = min(ans, costs[2] + cost(days, costs, j));
        return memo[i] = ans;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        memo.assign(n, -1);
        return cost(days, costs, 0);
    }
};