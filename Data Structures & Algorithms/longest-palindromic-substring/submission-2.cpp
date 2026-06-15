class Solution {
public:

    string longestPalindrome(string s) {
        string res;
        int size=0;
        int left , right;
       for (int i=0; i<s.size(); i++){
         left = i;
         right = i;
        while (left >=0 && right <=s.size() && s[left]==s[right]){
            string sub = s.substr(left, right-left+1);
            if (sub.size()>size){
                res = sub;
                size = sub.size();
            }
            left--;
            right++;

        }
         left = i;
         right = i+1;
          while (left >=0 && right <=s.size() && s[left]==s[right]){
            string sub = s.substr(left, right-left+1);
            if (sub.size()>size){
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
