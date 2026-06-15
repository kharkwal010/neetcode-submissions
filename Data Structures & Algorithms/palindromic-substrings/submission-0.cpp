class Solution {
public:
    int countSubstrings(string s) {
        int counter = 0;
        int left, right;
        for(int i = 0; i<s.size(); i++){
            left = i;
            right = i;
            while (left >=0 && right <s.size() && s[left]==s[right]){
                counter++;
                left--;
                right++;
            }
            left = i;
            right = i+1;
            while (left >=0 && right <s.size() && s[left]==s[right]){
                counter++;
                left--;
                right++;
            }

        }
        return counter;
        
    }
};
