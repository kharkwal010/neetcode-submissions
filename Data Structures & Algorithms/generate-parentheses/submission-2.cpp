class Solution {
public:
    void dfs(int i, int n, string comb, vector<string>& ans, int open){
        if(i==2*n){
            if(open==0){
                ans.push_back(comb);
            }
            return;
        }
        if(open<0) return;
        comb.push_back('(');
        dfs(i+1, n, comb, ans, open+1);
        comb.pop_back();
        comb.push_back(')');
        dfs(i+1, n, comb, ans, open-1);
    }
    vector<string> generateParenthesis(int n) {
        string comb;
        vector<string> ans;
        dfs(0, n, comb, ans, 0);
        return ans;
        
    }
};
