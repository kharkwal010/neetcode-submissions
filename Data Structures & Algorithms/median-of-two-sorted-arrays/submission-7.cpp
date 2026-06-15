class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size()) swap(nums1, nums2);
        int l1 = 0;
        int r1 = nums1.size()-1;
        int n = nums1.size() + nums2.size();
        int half = n / 2;
        bool one = (n%2==1);

        while(true){
            int m1 = (l1+r1)/2;
            if(l1>r1) m1 = nums1.size();
            int m2 = half - m1;
            int left1 = (m1>0) ? nums1[m1-1] : INT_MIN;
            int right1 = (m1>=nums1.size()) ? INT_MAX : nums1[m1];
            int left2 = (m2>0) ? nums2[m2-1] : INT_MIN;
            int right2 = (m2>=nums2.size()) ? INT_MAX : nums2[m2];
            if(left1<=right2 && left2<=right1){
                if(one) return min(right1, right2);
                else return ((double) min(right1, right2) + max(left1, left2)) / 2;
            }
            else if(left1>right2) r1 = m1 -1;
            else l1 = m1 + 1;
        }

    }
};
