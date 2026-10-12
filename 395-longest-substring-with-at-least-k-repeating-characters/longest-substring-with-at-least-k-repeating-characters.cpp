class Solution {
public:
    int substring(string s, int k, int l, int r, int& ans){
        if(l>r) return 0;
        // cout<<l<<" "<<r<<endl;
        vector<int> freq(26,0);
        for(int i=l; i<=r; i++) freq[s[i]-'a']++;
        int j = l;
        for(int i=l; i<=r; i++){
            if(freq[s[i]-'a']<k){
                ans = max(ans, substring(s, k, j, i-1, ans));
                while(j<=i){
                    freq[s[j]-'a']--;
                    j++;
                }
            }
        }
        ans = max(ans, (r-j+1));
        return (r-j+1);
    }
    int longestSubstring(string s, int k) {
        int ans = 0;
        substring(s, k, 0, s.size()-1, ans);
        return ans;
    }
};