class Solution {
public:
    vector<vector<int>> memo;
    bool check(string& s1, string& s2, string& s3, int i, int j){
        if(i+j==s3.size()) return true;
        if(memo[i][j]!=-1) return memo[i][j];
        bool ans = false;
        if(i<s1.size() && s1[i]==s3[i+j]) ans = ans || check(s1, s2, s3, i+1, j);
        if(j<s2.size() && s2[j]==s3[i+j]) ans = ans || check(s1, s2, s3, i, j+1);
        memo[i][j] = ans;
        return ans;

    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()){
            return false;
        }
        memo.resize(s1.size()+1, vector<int>(s2.size()+1, -1));
        return check(s1, s2, s3, 0,0);
    }
};