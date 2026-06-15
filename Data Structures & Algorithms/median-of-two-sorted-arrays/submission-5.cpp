class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) swap(nums2, nums1);
        int l = 0;
        int r = nums1.size()-1;
        int half = (nums1.size() + nums2.size())/2;
        while(true){
            int m = (l+r)/2;
            if(l>r) m= -1;
            int m2 = half - m - 1;
            int a1 = (m<0) ? INT_MIN : nums1[m];
            int b1 = (m+1>=nums1.size()) ? INT_MAX: nums1[m+1];
            int a2 = (m2-1<0) ? INT_MIN : nums2[m2-1];
            int b2 = (m2>=nums2.size()) ? INT_MAX: nums2[m2]; 
            if(a1>b2) r = m-1;
            else if(a2>b1) l = m+1;
            else{
                if((nums1.size() + nums2.size())%2==1) return min(b1, b2);
                else return (double)(max(a1, a2)+min(b1, b2))/2;
            }
        }
    }
};
