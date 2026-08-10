class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int unmatch = 0;
        int x = 0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i]){
                unmatch++;
                if(s1[i]=='x') x++;
            }
        }
        if(unmatch%2==1) return -1;
        if(x%2==0) return unmatch/2;
        return unmatch/2 + 1;
    }
};