class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for(int i = 31; i>=0; i--){
            int one = 1 & left>>i;
            int two = 1 & right>>i;
            if(one!=two) break;
            ans = ans | one<<i;
        }
        return ans;
    }
};