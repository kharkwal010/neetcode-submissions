class Solution {
public:
    int check(string& s, int l, int r, int& k){
        if(r-l+1<k) return 0;
        vector<int> freq(26, 0);
        for(int i=l; i<=r; i++) freq[s[i]-'a']++;
        int left = l;
        int ans = 0;
        for(int i=l; i<=r; i++){
            if(freq[s[i]-'a']<k){
                ans = max(ans, check(s, left, i-1, k));
                while(left<=i){
                    freq[s[left]-'a']--;
                    left++;
                }                
            }
        }
        // cout<<r-left+1<<endl;
        return max(ans, r-left+1);
    }
    int longestSubstring(string s, int k) {
        return check(s, 0, (int)s.size()-1, k);
    }
};