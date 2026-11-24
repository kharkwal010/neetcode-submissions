class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
       vector<vector<bool>> left(n, vector<bool>(26, 0));
       vector<vector<bool>> right(n, vector<bool>(26,0));
       vector<vector<bool>> visited(26, vector<bool>(26, 0));
       left[0][s[0]-'a'] = true;
       right[n-1][s[n-1]-'a'] = true;
       for(int i=1; i<n; i++){
            left[i][s[i]-'a'] = true;
            for(int j=0; j<26; j++) left[i][j] = left[i][j] || left[i-1][j];
       }

       for(int i=n-2; i>=0; i--){
            right[i][s[i]-'a'] = true;
            for(int j=0; j<26; j++) right[i][j] = right[i][j] || right[i+1][j];
       }

       int cnt = 0;
       for(int i=1; i<n-1; i++){
        for(int j=0; j<26; j++){
            if(left[i-1][j] && right[i+1][j]){
                if(!visited[s[i]-'a'][j]){
                    visited[s[i]-'a'][j] = true;
                    cnt++;
                }
            }
        }
        // cout<<i<<" "<<cnt<<endl;
       }
       return cnt;
       

    }
};