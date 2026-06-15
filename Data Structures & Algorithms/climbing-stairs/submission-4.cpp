class Solution {
public:
    int climbStairs(int n) {
        int two = 1;
        int one = 1;
        int curr = 1;
        while(n>=2){
            curr = one + two;
            two = one;
            one = curr;
            n--;
        }
        return curr;

    }
};
