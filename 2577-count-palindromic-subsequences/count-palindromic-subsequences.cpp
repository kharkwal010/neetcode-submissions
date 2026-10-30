class Solution {
public:
    int countPalindromes(string s) {
        int n = s.size();
        if(n<5) return 0;
        vector<int> right(10, 0);
        vector<vector<int>> rpair(10, vector<int>(10, 0));
        // generate a, b pair frequency:
        for(char c: s){
            int j = c - '0';
            for(int i=0; i<10; i++){
                rpair[i][j] += right[i];
            }
            right[j]++;
        }

        long long ans = 0;
        int mod = 1e9+7;

        vector<int> left(10,0);
        vector<vector<int>> lpair(10, vector<int>(10, 0));
        for(char c: s){
            int j = c - '0';
            right[j]--;
            for(int i=0; i<10; i++){
                rpair[j][i] -= right[i];
            } 

            for(int a=0; a<10; a++){
                for(int b=0; b<10; b++){
                    ans = (ans + 1LL*rpair[a][b] * lpair[b][a])%mod;
                }
            }

            for(int i=0; i<10; i++){
                lpair[i][j] += left[i];
            }
            left[j]++;
        }
        return ans;
    }
};