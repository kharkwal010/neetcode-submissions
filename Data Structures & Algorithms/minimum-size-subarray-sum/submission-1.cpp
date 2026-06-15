class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int length = INT_MAX;
        int sum = 0;
        int end = 0;
        
         // find the first sum ;

        while(end<nums.size()){
            sum = sum + nums[end];
            while(sum>=target){
                length = min(length, end -start +1);
                sum = sum - nums[start];
                start++;
            }
            end++;
        }
        if(length==INT_MAX ){
            return 0;
        }
        else{
            return length;
        }
       
    }
};