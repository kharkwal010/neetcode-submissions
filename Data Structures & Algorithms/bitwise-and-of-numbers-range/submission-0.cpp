class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for(int i=31; i>=0; i--){
            int one = (left>>i) & 1;
            int two = (right>>i) & 1;
            if(one!=two) return ans;
            if(one==1) ans |= (1 << i);
        }
        return ans;
    }
};