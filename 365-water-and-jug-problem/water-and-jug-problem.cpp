class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        int div = gcd(x, y);
        if(target>x+y) return false;
        if(target%div==0) return true;
        return false;
    }
};