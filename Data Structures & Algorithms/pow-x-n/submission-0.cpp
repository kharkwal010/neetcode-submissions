class Solution {
public:
    double myPow(double x, int n) {
        double prod = 1;
        if (n>=0){
        for (int i=0; i<n; i++){
            prod = prod * x;
        }
        }
        else{
            for(int i=0; i<abs(n); i++){
                prod = prod / x;
            }
        }
        return prod;
    }
};
