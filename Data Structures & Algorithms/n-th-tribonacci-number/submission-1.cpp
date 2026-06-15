class Solution {
public:
    int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
       }
       if(n==2){
        return 1;
        }
        int sum = 0;
        int one  = 0;
        int two = 1;
        int three = 1;
        for(int i=3; i<=n; i++){
            sum = one + two + three;
            one  = two;
            two = three;
            three = sum;
        }
        return sum;
    }
};