class Solution {
public:
    /*
    4   2   1   4   4
    1,1   2,2   4,3   4,1   4,0
    state curr budget num -->  1500 1000 and state kitna le sakte hn ye bhi h
    10
    */

    vector<vector<int>> memo;
    int mini;
    int dp(vector<vector<int>>& terms, int i, int budget){
        if(i==terms.size()) return budget/mini;
        if(memo[i][budget]!=-1) return memo[i][budget];
        int ans = 0;
        ans = max(ans, dp(terms, i+1, budget));
        if(budget - terms[i][0]>=0) ans = max(ans, 1 + terms[i][1] + dp(terms, i+1, budget - terms[i][0]));
        
        return memo[i][budget] = ans;
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<vector<int>> terms;
        mini = INT_MAX;
        for(int i=0; i<items.size(); i++){
            int cost = items[i][1];
            mini = min(mini, cost);
            int fac = items[i][0];
            int cnt = 0;
            for(int j=0; j<items.size(); j++){
                if(i==j) continue;
                if(items[j][0]%fac==0) cnt++;
            }
            terms.push_back({cost, cnt});
        }
        
        memo.resize(items.size(), vector<int>(budget+1, -1));
        return dp(terms, 0, budget);
        
    }
};