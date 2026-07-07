class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k==0) return 0;
        vector<int> count(3, 0);
        for(char c: s){
            count[c-'a']++;
        }
        if(count[0]<k || count[1]<k || count[2]<k) return -1;
        int ans = 0;
        int l = 0;
        vector<int> sec(3,0);
        for(int i=0; i<s.size(); i++){
            sec[s[i]-'a']++;
            while(sec[0]>count[0]-k || sec[1]>count[1]-k || sec[2]>count[2]-k){
                sec[s[l]-'a']--;
                l++;
            }
            ans = max(ans, i - l + 1);
        }
        return s.size() - ans;
    }
};