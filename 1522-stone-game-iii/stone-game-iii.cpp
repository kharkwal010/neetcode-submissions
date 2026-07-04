class Solution {
public:
    vector<vector<int>> memo;
    int sum(vector<int>& stone, int i, bool alice){
        if(i==stone.size()) return 0;
        if(memo[i][alice]!=INT_MAX) return memo[i][alice];
        int ans = (alice) ? INT_MIN : INT_MAX;
        int total = 0;
        for(int j = i; j<stone.size(); j++){
            if(j-i>=3) break;
            total += stone[j];
            if(alice) ans = max(ans, total + sum(stone, j+1, !alice));
            else ans = min(ans, sum(stone, j+1, !alice) - total);
        }
        return memo[i][alice] = ans;

    }
    string stoneGameIII(vector<int>& stoneValue) {
        memo.resize(stoneValue.size(), vector<int>(2, INT_MAX));
        int total = 0;
        for(int s: stoneValue) total += s;
        int term = sum(stoneValue, 0, true);
        // cout<<term<<endl;
        if(term==0) return "Tie";
        else if(term<0) return "Bob";
        return "Alice";
    }
};