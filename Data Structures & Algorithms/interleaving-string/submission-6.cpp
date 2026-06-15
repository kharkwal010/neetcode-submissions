class Solution {
public:
    unordered_map<string, bool> memo;
    bool check(string s1, string s2, string s3, int i, int j){
        if(i+j==s3.size()){
            return true;
        }
     
        string key = to_string(i)+"+"+to_string(j);
        if(memo.find(key)!=memo.end()){
            return memo[key];
        }
        bool one = false;
        if(i<s1.size() && s1[i]==s3[i+j]){
            one  = check(s1, s2, s3, i+1, j);
        }
        bool two = false;
        if(j<s2.size() && s2[j]==s3[i+j]){
            two = check(s1, s2, s3, i, j+1);
        }
        memo[key]=one || two;
        return memo[key];
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()){
            return false;
        }
        return check(s1, s2, s3, 0,0);
    }
};
