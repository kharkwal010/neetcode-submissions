class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int product_zero = 1;
        int i=0;
        int count = 0;
        
        for (int num: nums){
            if (num ==0){
               
                count++;
                product = num * product;
                
            }
            else{
                product = num * product;
                product_zero = num * product_zero;
                }
                
        }
        vector<int> arr;
        if (count > 1){return vector<int>(nums.size(), 0);}
        
        for (int num : nums){
            if (num != 0){            
            arr.push_back(product/num);
            }
            if (num == 0){
                arr.push_back(product_zero);
            }
        }
        
        

        
        return arr;
    }

};
