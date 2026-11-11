class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> freq(3, 0);
        for(char c: s) freq[c-'a']++;
        for(int i=0; i<3; i++) if(freq[i]<k) return -1;
        int ans = 0;
        int l = 0;
        for(int i=0; i<s.size(); i++){
            int j = s[i]-'a';
            freq[j]--;
            while(freq[j]<k){
                freq[s[l]-'a']++;
                l++;
            }
            ans = max(i-l+1, ans);
        }
        return s.size() - ans;
    }
};