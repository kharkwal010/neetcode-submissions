class Solution {
public:
    int characterReplacement(string s, int k) {
        int start =0;
        vector<int> count(26,0);
        int maxfreq=0;
        int extra = 0;
        int length = 0;

        for(int end=0; end<s.size(); end++){            
            int freq = ++count[s[end]-'A'];
            
            maxfreq = max(maxfreq, freq);
            extra = end-start+1 - maxfreq;

            
            if(extra>k){
                count[s[start]-'A']--;
                start++;
            }
            length = end-start+1;

        }
        return length;
    }
};