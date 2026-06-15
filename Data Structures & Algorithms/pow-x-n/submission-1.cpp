class Solution {
public:
    double myPow(double x, int n) {
        double prod = 1;
        for (int i=0; i<abs(n); i++){
            prod = prod * x;
        }
        if(n>=0) return prod;
        return 1/prod;
    }
};
