class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            swap(nums1, nums2);
        }

        int half = (nums1.size()+nums2.size())/2;
        bool one = true;
        if((nums1.size()+nums2.size())%2==0) one = false;
        int l1 = 0;
        int r1 = nums1.size()-1;
        int l2 = 0;
        int r2 = nums2.size()-1;

        while(true){
            int m1 = (l1 + r1) / 2;
            if(r1<0) m1 = -1;
            int m2 = half - m1 - 2;

            int left1 = (m1<0 ? INT_MIN : nums1[m1]);
            int right1 = (m1+1>=nums1.size() ? INT_MAX : nums1[m1+1]);
            int left2 = (m2<0 ? INT_MIN : nums2[m2]);
            int right2 = (m2+1>=nums2.size() ? INT_MAX : nums2[m2 + 1]);

            if(left1<=right2 && left2<=right1){
                if(one) return min(right1, right2);
                else return (double)(max(left1, left2)+min(right1, right2))/2;
            }
            else if(left1>right2) r1 = m1 - 1;
            else l1 = m1 + 1;
        }
    }
};
