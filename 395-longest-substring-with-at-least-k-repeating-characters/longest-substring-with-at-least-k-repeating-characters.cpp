class Solution {
public:
    int sub(string& s, int&k, int l, int r){
        vector<int> freq(26, 0);
        for(int i=l; i<=r; i++) freq[s[i]-'a']++;
        int ans = 0;
        int left = l;
        for(int i=l; i<=r; i++){
            if(freq[s[i]-'a']<k){
                ans = max(ans, sub(s, k, left, i-1));
                while(left<=i){
                    freq[s[left]-'a']--;
                    left++;
                }
            }
        }
        return max(ans, r-left+1);
    }
    int longestSubstring(string s, int k) {
      return sub(s, k, 0, s.size()-1);
        
    }
};