class Solution {
public:
    string check(string& s, int m){
        // if(m!=2) return "";
        long long power1 = 1;
        long long power2 = 1;
        long long base1 = 31;
        long long base2 = 39;
        int mod2 = 1e9+9;
        int mod1 = 1e9+7;
        long long hash1 = (s[m-1]-'a'+1);
        long long hash2 = (s[m-1]-'a'+1);
        set<pair<long long,long long>> visited;
        for(int i=m-2; i>=0; i--){
            power1 = (power1*base1) % mod1;
            hash1 = (hash1 + power1*(s[i]-'a'+1))%mod1;

            power2 = (power2*base2) % mod2;
            hash2 = (hash2 + power2*(s[i]-'a'+1))%mod2;
        }

        visited.insert({hash1, hash2});
        // cout<<m<<": "<<endl;
        // cout<<hash<<endl;
        for(int i=m; i<s.size(); i++){
            hash1 = (hash1 - (power1*(s[i-m]-'a'+1))%mod1 + mod1)%mod1;
            hash1 = ((hash1 * base1)%mod1 + (s[i]-'a'+1))%mod1;

            hash2 = (hash2 - (power2*(s[i-m]-'a'+1))%mod2 + mod2)%mod2;
            hash2 = ((hash2 * base2)%mod2 + (s[i]-'a'+1))%mod2;
            // cout<<hash<<endl;
            if(visited.count({hash1, hash2})){
                return s.substr(i-m+1, m);
            }
            visited.insert({hash1, hash2});            
        }
        return "";
    }


    string longestDupSubstring(string s) {
        int l = 1;
        int r = s.size()-1;
        string ans = "";
        while(l<=r){
            int m = (l + (r-l)/2);
            string val = check(s, m);
            // cout<<val<<endl;
            // cout<<endl;
            if(val.size()==0){
                r = m-1;
            }
            else{
                ans = val;
                l = m+1;
            }
        }
        return ans;
    }
};