class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        while(l<=r){
            int m = l + (r-l) / 2;
            if((long long)m*m > x) r = m-1;
            else if((long long)m*m <= x) l = m+1;
        }
        return l-1;
    }
};