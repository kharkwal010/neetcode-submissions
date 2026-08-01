class Solution {
public:
    void comb(int k, int n, vector<vector<int>>& ans, vector<int> terms, int j){
        if(n<0) return;
        if(k==0){
            if(n==0) ans.push_back(terms);
            return;
        }
        for(int i=j; i<10; i++){
            terms.push_back(i);
            comb(k-1, n-i, ans, terms, i+1);
            terms.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        comb(k, n, ans, {}, 1);
        return ans;
    }
};