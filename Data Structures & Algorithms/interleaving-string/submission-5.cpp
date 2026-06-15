class Solution {
public:
    unordered_map<string, bool> memo;
    bool check(string s1, string s2, string s3, int one, int two){
        if(one+two == s3.size()){
            if(one==s1.size() && s2.size()==two){
                return true;
            }
            return false;
        }
        string key = to_string(one)+"#"+to_string(two);
        if(memo.find(key)!=memo.end()){
            return memo[key];
        }
        bool first = false;
        bool second = false;
        if(s1[one]==s3[one+two]){
           first = check(s1, s2, s3, one+1, two);
        }
        if(s2[two]==s3[one+two]){
            second = check(s1, s2, s3, one, two+1);
        }
        memo[key] = first || second;
        return memo[key];
    }


    bool isInterleave(string s1, string s2, string s3) {
        return check(s1, s2, s3, 0, 0);
    }
};
