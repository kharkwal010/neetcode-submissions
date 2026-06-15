class Solution {
public:
    int characterReplacement(string s, int k) {
       vector<int> count(26,0);
       int start = 0;
       int ans=1;
       int extra = 0;
       int maxfreq = 0;
       for(int end=0; end<s.size(); end++){
        int curr = s[end]-'A';
        count[curr]++;
        maxfreq = max(maxfreq, count[curr]);
        int length = end - start +1;
        extra = length -maxfreq;
        while(extra> k){
            count[s[start]-'A']--;
            start++;
            maxfreq = *max_element(count.begin(), count.end());
            extra = start - end + 1 -maxfreq;
        }     
        ans = max(end - start +1, ans);        
       }
       return ans;
    }
};
