class Solution {
public:
    int climbStairs(int n) {
        int one = 1;
        int two = 1;
        int curr;
        while(n>=2){
         curr = one + two;
            two=one;
            one =curr;
            n--;
        }
        if (curr){
        return curr;
        }
        return 1;
    }
};
