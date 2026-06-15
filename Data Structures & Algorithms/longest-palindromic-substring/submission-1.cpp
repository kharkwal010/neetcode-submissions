class Solution {
public:

    string longestPalindrome(string s) {
        int ans = 0;
        string result;
       for(int i=0; i<s.size(); i++){
        int length = 0;
        int left = i;
        int right = i;
        string sub;
        while(left >=0 && right < s.size() && s[left]==s[right]){
            length = right - left +1;
            sub = s.substr(left,length);
            right++;
            left--;
            
        }
        if(length > ans){
            result = sub;
        }
        ans = max(length , ans);
        left = i;
        right = i+1;
        while(left >=0 && right < s.size() && s[left]==s[right]){
            length =right - left +1;
            sub = s.substr(left,length);
            right++;
            left--;
        }
        if(length > ans){
            result = sub;
        }
        ans = max(length , ans);
       }
       return result;
    }
};
