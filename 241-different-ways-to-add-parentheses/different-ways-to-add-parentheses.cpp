class Solution {
public:
    unordered_map<string, vector<int>> memo;
    vector<int> ways(string expression){
        if(memo.count(expression)) return memo[expression];
        vector<int> ans;
        for(int i=0; i<expression.size(); i++){
            if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*'){
                string left = expression.substr(0, i);
                string right = expression.substr(i+1);
                vector<int> lele = ways(left);
                vector<int> rele = ways(right);
                for(int l: lele){
                    for(int r: rele){
                        if(expression[i]=='+') ans.push_back(l+r);
                        else if(expression[i]=='-') ans.push_back(l-r);
                        else ans.push_back(l*r);
                    }
                }
            }
        }
        if(ans.empty()) ans.push_back(stoi(expression));
        return memo[expression] = ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return ways(expression);
    }
};