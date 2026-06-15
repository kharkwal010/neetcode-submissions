class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size()<=1){
            return 0;
        }
        int count = 0;
        int right=0;
        for(int i=0; i<nums.size(); i++){
            int prevright = right;
            while(i<=prevright){
            right= max(i+nums[i],right);  
            i++;      
            }
            count++;
     
            if(right>=nums.size()-1){
                return count;
            }
            i--;
        }
        return -1;
        
    }
};
