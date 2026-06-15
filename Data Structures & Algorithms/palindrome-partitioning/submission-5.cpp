class Solution {
public:
    bool palin(string s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void pal(string s, int i, vector<vector<string>>& comb, vector<string> term){
        if(i==s.size()){
            comb.push_back(term);
            return;
        }
        for(int j=s.size()-1; j>=i; j--){
            if(palin(s, i, j)){
                term.push_back(s.substr(i, j-i+1));
                pal(s, j+1, comb, term);
                term.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> comb;
        vector<string> term;
        pal(s, 0, comb, term);
        return comb;
    }
};
