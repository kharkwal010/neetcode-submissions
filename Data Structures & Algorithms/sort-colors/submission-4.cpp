class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        int m = s;
        while(m<=e){
            if(nums[m]==0){
                swap(nums[s], nums[m]);
                s++;
                if(s>m) m = s;
            }
            else if(nums[m]==2){
                swap(nums[e], nums[m]);
                e--;
            }
            else m++;
        }
    }
};