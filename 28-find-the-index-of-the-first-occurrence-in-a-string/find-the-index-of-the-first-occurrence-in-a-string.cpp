class Solution {
public:
    int strStr(string haystack, string needle) {
        int j = needle.size();
        int k = haystack.size();
        for(int i=0; i<= k - j; i++){
            if(haystack[i]==needle[0]){
                string sub = haystack.substr(i, j);
                if(sub==needle) return i;
            }
        }
        return -1;
    }
};