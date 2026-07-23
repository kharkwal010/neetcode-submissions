class Solution {
public:
    int calc(int val, int tar){
        if(tar<=val) return val-tar;
        if(tar%2==0) return 1 + calc(val, tar/2);
        else return 2 + calc(val, (tar+1)/2);
    }
    int brokenCalc(int startValue, int target) {
        return calc(startValue, target);
    }
};