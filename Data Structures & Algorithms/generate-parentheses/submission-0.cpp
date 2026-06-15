class Solution {
public:
    void combinations(int n, int open, int close, vector<string>& ans, string curr){
        if(open>n || open<close){
            return;
        }
        if(curr.size()==2*n){
            ans.push_back(curr);
            return;
        }
        curr.push_back('(');
        combinations(n, open+1, close, ans, curr);
        curr.pop_back();
        curr.push_back(')');
        combinations(n, open, close+1, ans, curr);
        curr.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        combinations(n, 0, 0, ans, curr);
        return ans;
        
    }
};
