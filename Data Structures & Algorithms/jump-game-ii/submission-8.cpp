class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
       int far=0;
       int count=0;
       int start = 0;
       int prevfar = -1;
       while(true){
        start = prevfar+1;
        prevfar = far;
        for(int i=start; i<=prevfar; i++){
            far = max(far, i+nums[i]);
        }
        count++;
        if(far>=nums.size()-1){
            return count;
        }
       }       
    }
};

