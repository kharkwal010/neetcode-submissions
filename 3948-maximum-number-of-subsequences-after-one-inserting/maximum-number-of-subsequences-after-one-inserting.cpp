class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        vector<int> prevl(n, 0);
        vector<int> nextt(n, 0);
        int l = 0;
        int t = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='L') l++;
            prevl[i] = l;
        }
        for(int j=n-1; j>=0; j--){
            if(s[j]=='T') t++;
            nextt[j] = t;
        }
        long long count = 0;
        long long cumc = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='C'){
                cumc+=prevl[i];
            }
            if(s[i]=='T') count+=cumc;
        }
        long long maxc = 0;
        long long maxl = 0;
        long long maxt = 0;

        for(int i=0; i<n; i++){
            maxc = max(maxc, (long long)prevl[i] * nextt[i]);
            if(s[i]=='C'){
                maxl = maxl + nextt[i];
                maxt = maxt + prevl[i];
            }

        }
        // cout<<count<<" "<<maxc<<" "<<maxl<<" "<<maxt<<endl;
        long long add = max(maxc, max(maxl, maxt));
        return count + add;


    }
};