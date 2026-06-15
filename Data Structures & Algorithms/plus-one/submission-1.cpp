class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       int last =  digits.size()-1 ;
       int remainder = 1;
       for (int i=last; i>=0; i--){
            int temp = digits[i]+remainder;
            digits[i] = temp%10;
            remainder = temp /10;
       }
       if (remainder != 1){
            return digits;
       }
       vector<int> ans(digits.size()+1,0);
       ans[0]=1;
       return ans;
    }
};
