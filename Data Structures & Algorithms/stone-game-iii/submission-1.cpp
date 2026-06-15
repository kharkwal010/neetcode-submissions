class Solution {
public:
    vector<vector<int>> memo;
    int score(vector<int>& stone, int i, bool alice){
        if(i==stone.size()) return 0;
        if(memo[alice][i]!=INT_MIN) return memo[alice][i];
        int curr = 0;
        int res = (alice) ? INT_MIN : INT_MAX;
        for(int j=0; j<3; j++){
            if(i+j>=stone.size()) break;
            curr += stone[i+j];
            if(alice) res = max(res, curr + score(stone, i+j+1, !alice));
            else res = min(res, score(stone, i+j+1, !alice));
        }
        memo[alice][i] = res;
        return res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memo.resize(2, vector<int>(n+1, INT_MIN));
        double sum = 0;
        for(int n: stoneValue){
            sum+=n;
        }
        sum = sum/2;
        int alice = score(stoneValue, 0, true);
        if(alice==sum) return "Tie";
        else if(alice>sum) return "Alice";
        return "Bob";
    }
};