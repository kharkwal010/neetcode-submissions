class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size = nums1.size()-1;
        for(int i=size; i>=0; i--){
            if(m-1<0){
                nums1[i] = nums2[n-1];
                n--;
            }
            else if(n-1<0){
                nums1[i] = nums1[m-1];
                m--;
            }
            else if(nums1[m-1]<nums2[n-1]){
                nums1[i] = nums2[n-1];
                n--;
            }
            else{
                nums1[i] = nums1[m-1];
                m--;
            }
        }
        return;
    }
};