class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        // unordered_map<int,int> counter;
        vector<int> counter(26,0);
        int maxf=0;
        int length=0;
        while(r<s.size()){
            counter[s[r]-'A']++;
            maxf=max(maxf, counter[s[r]-'A']);
            if(r-l+1-maxf<=k){
            length = max(r-l+1, length);    
                r++;
            }
            else{
                counter[s[l]-'A']--;
                l++;
                r++;
                
            }
        }
        return length;
    }
};
