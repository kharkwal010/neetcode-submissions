class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        // unordered_map<int,int> counter;
        vector<int> counter(26,0);
        int maxf=0;
        int length=0;
        for(int r=0; r<s.size(); r++){
            counter[s[r]-'A']++;
            maxf=max(maxf, counter[s[r]-'A']);
            if(r-l+1-maxf<=k){
            length = max(r-l+1, length);
            }
            else{
                counter[s[l]-'A']--;
                l++;                
            }
        }
        return length;
    }
};
