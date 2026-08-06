class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int r = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                while(r<nums.size()){
                    if(r>i && nums[r]!=0){
                        swap(nums[i], nums[r]);
                        break;
                    }
                    r++;
                }
                if(r==nums.size()) break;
            }
        }
        return;


    }
};