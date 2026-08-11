class Solution {
public:
    vector<vector<bool>> palindrome;
    bool palin(string& s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    bool check(string& s, int i, int k){
        if(i==s.size()) return false;
        if(k==2) return palindrome[i][s.size()-1];
        bool ans = false;
        for(int j=i; j<s.size(); j++){
            if(palindrome[i][j]){
                ans = ans || check(s, j+1, k+1);
            }
        }
        return ans;
    }
    bool checkPartitioning(string s) {
        int n = s.size();
        palindrome.resize(n, vector<bool>(n, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                palindrome[i][j] = palin(s, i, j);
            }
        }
        return check(s, 0, 0);
        

    }
};