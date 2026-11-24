class Solution {
public:
    int countPalindromes(string s) {
        int mod = 1e9 + 7;
        long long cnt = 0;
        int n = s.size();
        if(n<5) return 0;
        vector<int> right(10,0);
        vector<vector<int>> rpairs(10, vector<int>(10, 0));
        for(int i=0; i<n-1; i++){
            int k = s[i] - '0';
            for(int j=0; j<10; j++){
                rpairs[j][k] += right[j];
            }
            right[k]++;
        }
        vector<int> left(10, 0);
        vector<vector<int>> lpairs(10, vector<int>(10, 0));
        for(int i=n-1; i>0; i--){
            int k = s[i]-'0';
            for(int j=0; j<10; j++){
                lpairs[k][j] += left[j];
            }
            left[k]++;
            int x = s[i-1]-'0';
            right[x]--;
            for(int j=0; j<10; j++){
                rpairs[j][x] -= right[j];
            }

            for(int m=0; m<10; m++){
                for(int n=0; n<10; n++){
                    cnt = (cnt + 1LL*rpairs[m][n] * lpairs[n][m])%mod;
                }
            }
        }
        return cnt;
    }
};