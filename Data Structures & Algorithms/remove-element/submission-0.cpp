class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int j = nums.size()-1;
        int count = 0;
        int i = 0;
        while(i<=j){
            if(nums[i]==val){
                swap(nums[i], nums[j]);
                j--;
                count++;
            }
            else i++;
        }
        return n-count;
    }
};