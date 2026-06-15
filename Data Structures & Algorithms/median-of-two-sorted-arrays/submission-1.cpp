class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();
        if(s1>s2){
            swap(nums1, nums2);
            swap(s1, s2);
        }
        int l1 = 0;
        int r1 = s1-1;
        int l2 = 0;
        int r2 = s2-1;
        int half = (s1+s2)/2;
        bool one = true;
        if((s1+s2)%2==0) one=false;
        while(true){
            int m1 = (l1+r1)/2;
            if(r1<0) m1 = -1;
            int m2 = half - m1 - 2;
            int left1  = (m1 < 0 ? INT_MIN : nums1[m1]);
            int right1 = (m1+1 >= s1 ? INT_MAX : nums1[m1+1]);

            int left2  = (m2 < 0 ? INT_MIN : nums2[m2]);
            int right2 = (m2+1 >= s2 ? INT_MAX : nums2[m2+1]);

            if(left1 <= right2 && left2 <= right1){
                if(one) return (double)min(right1, right2);
                else return (double)(max(left1,left2) + min(right1, right2))/2;
            }
            else if(left2>right1){
                l1 = m1+1;
            }
            else r1 = m1-1;
        }
        
    }
};
