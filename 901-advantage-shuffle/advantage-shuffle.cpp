class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int>> match;
        vector<int> nums = nums2;
        sort(nums1.begin(), nums1.end());
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums2.size()- 1;
        for(int i=0; i<nums1.size(); i++){
            if(nums1[i]>nums[l]){
                match[nums[l]].push_back(nums1[i]);
                l++;
            }
            else{
                match[nums[r]].push_back(nums1[i]);
                r--;
            }
        }
        for(int i=0; i<nums2.size(); i++){
            int x = nums2[i];
            nums2[i] = match[nums2[i]].back();
            match[x].pop_back();
        }
        return nums2;

    }
};