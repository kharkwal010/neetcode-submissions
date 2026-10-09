class Solution {
public:
    // vector<vector<vector<vector<long long>>>> memo;
    long long memo[16][80][80][2];
    long long terms(string& s, int i, int evensum, int oddsum, bool tight){
        if(i==s.size()) return (evensum==oddsum);
        if(memo[i][evensum][oddsum][tight]!=-1) return memo[i][evensum][oddsum][tight];
        int maxi = (tight) ? s[i]-'0' : 9;
        long long ans = 0;
        
            int newe = evensum;
            int newo = oddsum;
        for(int j=0; j<=maxi; j++){
            if(i%2==0){
                newe = evensum + j;
            }
            else newo = oddsum + j;
            ans += terms(s, i+1, newe, newo, (tight && j==s[i]-'0'));
        }
        return memo[i][evensum][oddsum][tight] = ans;
    }
    long long num(long long n){
        string s = to_string(n);
        int sz = s.size();
        int even = (sz%2 + sz/2)*9;
        int odd = (sz/2)*9;
        // memo.assign(sz, vector<vector<vector<long long>>>(even+1, vector<vector<long long>>(odd+1, vector<long long>(2, -1))));
        memset(memo, -1, sizeof(memo));
        return terms(s, 0, 0, 0, true);
        
    }
    long long countBalanced(long long low, long long high) {
        return num(high) - num(low-1);
    }
};