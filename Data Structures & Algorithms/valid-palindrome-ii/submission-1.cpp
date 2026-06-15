class Solution {
public:
    bool ispal(string s, int start, int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;            
        }
        return true;
    }
    bool validPalindrome(string s) {
       int start = 0;
       int end = s.size()-1;
       while(start<end){
            if(s[start]!=s[end]){
                return ispal(s,start+1, end) || ispal(s, start, end-1);
            }
            start++;
            end--;
       }
       return true;
    }
};