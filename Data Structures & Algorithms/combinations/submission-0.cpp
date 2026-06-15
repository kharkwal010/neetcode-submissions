class Solution {
public:
    void terms(int i, int n, int k, vector<vector<int>>& ans, vector<int> comb){
        if(i==n+1){
            if(comb.size()==k) ans.push_back(comb);
            return;
        }
        terms(i+1, n, k, ans, comb);
        comb.push_back(i);
        terms(i+1, n, k, ans, comb);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        terms(1, n , k, ans, comb);
        return ans;
    }
};