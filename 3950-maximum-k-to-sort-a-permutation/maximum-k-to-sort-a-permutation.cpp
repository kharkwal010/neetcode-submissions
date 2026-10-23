class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int> elements;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=i) elements.push_back(nums[i]);
        }
        if(elements.size()==0) return 0;
        int ans = elements[0];
        for(int i=1; i<elements.size(); i++) ans = ans & elements[i];
        return ans;
    }
};