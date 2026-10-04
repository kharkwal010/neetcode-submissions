class Solution {
public:
    vector<vector<int>> memo;
    int maxitem(vector<vector<int>>& items, int budget, vector<int>& free, int i, int& mini){
        if(i==items.size()) return budget/mini;
        if(memo[i][budget]!=-1) return memo[i][budget];
        int ans = 0;
        ans = max(ans, maxitem(items, budget, free, i+1, mini));
        if(items[i][1]<=budget) ans = max(ans, free[i] + 1 + maxitem(items, budget-items[i][1], free, i+1, mini));
        return memo[i][budget] = ans;
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int mini = INT_MAX;
        vector<int> free(items.size(), 0);
        for(int i=0; i<items.size(); i++){
            int count = 0;
            mini = min(mini, items[i][1]);
            for(int j=0; j<items.size(); j++){
                if(i==j) continue;
                if(items[j][0]%items[i][0]==0) count++;
            }
            free[i] = count;
        }
        // for(int f: free) cout<<f<<" ";
        memo.resize(items.size(), vector<int>(budget+1, -1));
        return maxitem(items, budget, free, 0, mini);
        
    }
};