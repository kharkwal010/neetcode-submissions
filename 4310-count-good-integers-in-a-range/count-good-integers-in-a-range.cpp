class Solution {
public:
    vector<vector<vector<long long>>> memo;
    long long terms(string& s, int i, int prev, bool small, int& k){
        if(i==s.size()) return 1;
        if(memo[i][prev][small]!=-1) return memo[i][prev][small];
        int curr = s[i] - '0';
        int start = max(0, prev - k);
        int end = min(9, prev + k);
        if(!small) end = min(end, s[i]-'0');
        long long ans = 0;
        for(int j=start; j<=end; j++){
            bool free = small || s[i]-'0'>j;
            ans += terms(s, i+1, j, free, k);
        }
        return memo[i][prev][small] = ans;
    }
    long long fun(long long l, int k){
        string s1 = to_string(l);
        int n1 = s1.size();
        memo.assign(n1, vector<vector<long long>>(10, vector<long long>(2, -1)));
        long long ans = 0;
        for(int i=0; i<n1; i++){
            int mx = (i==0) ? s1[0] - '0' : 9;
            for(int j=1; j<=mx; j++){
                if(i==0 && j==mx) ans += terms(s1, i+1, j, false, k);
                else ans+=terms(s1, i+1, j, true, k);
            }

        }
        return ans;
    }
    long long goodIntegers(long long l, long long r, int k) {
        return (fun(r, k) - fun(l-1, k));
    }
};