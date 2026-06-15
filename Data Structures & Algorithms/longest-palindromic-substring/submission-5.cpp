class Solution {
public:

    string longestPalindrome(string s) {
        string res;
        int size=0;
        int left , right;
        string sub;
       for (int i=0; i<s.size(); i++){
         left = i;
         right = i;
        while (left >=0 && right <s.size() && s[left]==s[right]){            
            if (right-left+1>size){
                sub = s.substr(left, right-left+1);
                res = sub;
                size = sub.size();
            }
            left--;
            right++;

        }
         left = i;
         right = i+1;
          while (left >=0 && right <s.size() && s[left]==s[right]){
            if (right-left+1>size){
                sub = s.substr(left, right-left+1);
                res = sub;
                size = sub.size();
            }
            left--;
            right++;

        }
       }
       return res;
    }
};
