class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> left(n);
        vector<int> right(n);
        int overall = 0;
        for(int i=0; i<s.size(); i++){
            int curr = 1<<(s[i]-'a');
            overall = overall | curr;
            left[i] = overall;
        }
        overall = 0;
        for(int i=n-1; i>=0; i--){
            int curr = 1<<(s[i]-'a');
            overall = overall | curr;
            right[i] = overall;
        }
        int count = 0;
        vector<vector<bool>> visited(26, vector<bool>(26, false));
        for(int i=1; i<s.size()-1; i++){
            int curr = s[i]-'a';
            for(int j=0; j<26; j++){
                if(visited[curr][j]) continue;
                if((left[i-1]>>j & 1) & (right[i+1]>>j & 1)){
                    visited[curr][j] = true;
                    count++;
                }
            }
        }
        return count;
    }
};