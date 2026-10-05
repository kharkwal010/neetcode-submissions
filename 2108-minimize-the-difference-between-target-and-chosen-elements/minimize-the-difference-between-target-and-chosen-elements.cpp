class Solution {
public:
    vector<vector<int>> memo;
    vector<int> value;
    int calc(vector<vector<int>>& mat, int target, int i){
        if(target<0){
            target -= value[i];
            return abs(target);
        }
        if(i==mat.size()) return abs(target);
        if(memo[target][i]!=-1) return memo[target][i];
        int ans = INT_MAX;
        for(int j=0; j<mat[0].size(); j++){
            ans = min(ans, calc(mat, target - mat[i][j], i+1));
        }
        return memo[target][i] = ans;

    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();

      memo.resize(target+1, vector<int>(m, -1));
       value.resize(m, 0);
       for(int i=0; i<m; i++){
        int val = *min_element(mat[i].begin(), mat[i].end());
        value[i] = val;
       }
       for(int i=m-2; i>=0; i--){
            value[i] += value[i+1];
       }
       value.push_back(0);
       return calc(mat, target, 0); 
    }
};