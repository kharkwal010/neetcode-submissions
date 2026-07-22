class Solution {
public:
    bool isPowerOfTwo(int n) {
        int one = 0;
        if((n>>31 & 1)==1) return false;
        for(int i=0; i<32; i++){
            one += (n>>i & 1);
        }
        if(one==1) return true;
        return false;
    }
};