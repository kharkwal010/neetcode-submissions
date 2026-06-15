class Solution {
public:
    void gen(int n, int open, int close, vector<string>& ans, int layer, string term){
        if(open>n || close>open){
            return;
        }
        if(2*n==layer){
            ans.push_back(term);
        }
        gen(n, open+1, close, ans, layer + 1, term+"(");
        gen(n, open, close+1, ans, layer+1, term+")");
    }
    
    vector<string> generateParenthesis(int n) {
       vector<string> ans;
       gen(n, 0, 0, ans, 0, "");
       return ans;
    }
};
