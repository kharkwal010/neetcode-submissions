class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> freq;
        int n = nums1.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                freq[nums3[i] + nums4[j]]++;
            }
        }
        int count = 0;
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                int tar = -(nums1[i] + nums2[j]);
                count+= freq[tar];
            }
        }
        return count;
        
    }
};