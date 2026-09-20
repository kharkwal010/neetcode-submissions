class Solution {
public:
    vector<vector<vector<long long>>> memo;
    long long count(string& s, int i, int prev, bool tight, int& k){
        if(i==s.size()) return 1;
        if(memo[i][prev][tight]!=-1) return memo[i][prev][tight];
        long long ans = 0;
        int maxi;
        int mini;
        if(prev==10){
            maxi = 9;
            mini = 0;
        }
        else{
            maxi = min(9, prev + k);
            mini = max(0, prev - k);
        }
        if(tight) maxi = min(s[i]-'0', maxi);
        // cout<<prev<<" "<<mini<<" "<<maxi<<endl;
        for(int t=mini; t<=maxi; t++){
            int p = (t==0 && prev==10) ? 10 : t;
            ans += count(s, i+1, p, (tight && (t==s[i]-'0')), k);
        }
        return memo[i][prev][tight] = ans;

    }
    long long goodIntegers(long long l, long long r, int k) {
      string one = to_string(l-1);
      string two = to_string(r);
      memo.assign(one.size(), vector<vector<long long>>(11, vector<long long>(2, -1)));
      long long first = count(one, 0, 10, true, k);
      memo.assign(two.size(), vector<vector<long long>>(11, vector<long long>(2, -1)));
      long long second = count(two, 0, 10, true, k);
    //   cout<<first<<" "<<second;
      return second - first;
    }
};