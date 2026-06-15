class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int> letters(256,0);
       int start = 0;
       int ans = 0;
       for(int i=0; i<s.size(); i++){
        letters[s[i]]++;
        if(letters[s[i]]>1){
            while(s[i]!=s[start]){
                letters[s[start]]--;
                start++;
            }
            letters[s[start]]--;
            start++;
        }
        int length = i-start+1;
        ans = max(ans, length);
       }
       return ans;
    }
};
