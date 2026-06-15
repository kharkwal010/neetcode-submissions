class Solution {
public:
    bool ispal(string s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void palin(string s, vector<vector<string>>& ans, vector<string> comb, int curr){
        if(curr==s.size()) ans.push_back(comb);
        for(int i=curr; i<s.size(); i++){
            if (ispal(s, curr, i)){
                string sub = s.substr(curr, i-curr+1);
                comb.push_back(sub);
                palin(s, ans, comb, i+1);
                comb.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> comb;
        palin(s, ans, comb, 0);
        return ans;
    }
};
