class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        if(n2>n1) return false;
        int j = 0;
        for(int i=0; i<n1; i++){
            int curr = str1[i];
            int nxt = (str1[i]=='z') ? 'a' : curr+1;
            if(str2[j]==curr || str2[j]==nxt){
                j++;
                if(j==str2.size()) return true;
            }
        }
        return false;
        
    }
};