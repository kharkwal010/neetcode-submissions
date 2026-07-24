class Solution {
public:
    vector<vector<int>> memo;
    int coins(vector<int>& terms, int target, int i){
        if(target<0) return 0;
        if(target==0) return 1;
        if(memo[target][i]!=-1) return memo[target][i];
        int ans = 0;
        for(int j=i; j<terms.size(); j++){
            if(target-terms[j]<0) break;
            ans += coins(terms, target-terms[j], j);
        }
        return memo[target][i] = ans;

    }
    vector<int> findCoins(vector<int>& numWays) {
        vector<int> terms;
        int i=0;
        int n = numWays.size();
        while(i<n){
            i++;
            if(numWays[i-1]==0) continue;
            else if(numWays[i-1]==1){
                terms.push_back(i);
                break;
            }
            else return{};
        }
        for(int j=i; j<n; j++){
            memo.assign(j+2, vector<int>(n,-1));
            int t = coins(terms, j+1, 0);
            if(numWays[j]==t) continue;
            else{
                memo.assign(j+2, vector<int>(n,-1));
                terms.push_back(j+1);
                t = coins(terms, j+1, 0);
                if(numWays[j]!=t) return{};                
            }
        }
        return terms;


    }
};