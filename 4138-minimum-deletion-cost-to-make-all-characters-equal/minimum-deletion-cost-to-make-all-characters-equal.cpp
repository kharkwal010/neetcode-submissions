class Solution {
public:
    long long preserve(string& s, vector<int>& cost, char c){
        long long ans = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]!=c){
                ans += cost[i];
            }
        }
        return ans;
    }
    long long minCost(string s, vector<int>& cost) {
        vector<bool> present(26, 0);
        for(char c: s){
            present[c-'a'] = true;
        }
        long long ans = LLONG_MAX;
        for(int i=0; i<26; i++){
            if(present[i]){
                ans = min(ans, preserve(s, cost, 'a'+i));
            }
        }
        return ans;
    }
};