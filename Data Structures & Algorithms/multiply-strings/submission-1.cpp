class Solution {
public:
    string multiply(string num1, string num2) {
        
        long d1 = 0;
        for(int i=0; i<num1.size(); i++){
            d1 = d1*10 + (num1[i]-'0') ;
           
        }
       
        long d2 = 0;
        for(int i=0; i<num2.size(); i++){
            d2 = d2*10 + (num2[i]-'0') ;
          
        }
        long prod = d1 * d2;
        if (prod==0){
            return "0";
        }
        string result;
        while(prod > 0){
            int term = prod % 10;
            result.push_back('0' + term);
            prod = prod / 10;

        }
        
        reverse(result.begin(), result.end());
        return result;
        
    }
};
