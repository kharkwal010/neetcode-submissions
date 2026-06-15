class Solution {
public:
    int jump(vector<int>& nums) {
       int start = 0;
       int far = 0;
       int count=0;
       while(far<nums.size()-1){
        int prevfar = far;
        for(int i=start; i<=prevfar; i++){
            far = max(i+nums[i], far);
        }
        count++;
        start = prevfar+1;
       } 
       return count;     
    }
};

