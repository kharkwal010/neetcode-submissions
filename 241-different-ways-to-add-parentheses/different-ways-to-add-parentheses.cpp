class Solution {
public:
    unordered_map<string, vector<int>> memo;
    vector<int> ways(string s){
        if(memo.count(s)) return memo[s];
        vector<int> ans;
        bool present = false;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='-' || s[i]=='+' || s[i]=='*'){
                present = true;
                string left = s.substr(0, i);
                string right = s.substr(i+1);
                vector<int> l = ways(left);
                vector<int> r = ways(right);
                for(int ele1: l){
                    for(int ele2: r){
                        if(s[i]=='+') ans.push_back(ele1 + ele2);
                        else if(s[i]=='-') ans.push_back(ele1 - ele2);
                        else ans.push_back(ele1 * ele2);
                    }
                }
            }
        }
        if(!present) ans.push_back(stoi(s));
        return memo[s] = ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return ways(expression);
    }
};