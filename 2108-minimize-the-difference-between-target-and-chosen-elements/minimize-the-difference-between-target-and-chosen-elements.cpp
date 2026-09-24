class Solution {
public:
    vector<vector<int>> memo;
    vector<int> negsum;
    int value(vector<vector<int>>& mat, int target, int i){
        if(i==mat.size()) return abs(target);
        if(target<=0){
            target -= negsum[i];
            return abs(target);
        }
        if(memo[target][i]!=-1) return memo[target][i];
        int ans = INT_MAX;
        for(int j=0; j<mat[i].size(); j++){
            ans = min(ans, value(mat, target-mat[i][j], i+1));
        }
        return memo[target][i] = ans;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int r = mat.size();
        int c = mat[0].size();
        memo.resize(target+1, vector<int>(r, -1));
        negsum.resize(r);
        for(int i=0; i<r; i++){
            negsum[i] = *min_element(mat[i].begin(), mat[i].end());
        }
        for(int i=r-2; i>=0; i--){
            negsum[i]+=negsum[i+1];
        }
        negsum.push_back(0);
        return value(mat, target, 0);
        
    }
};