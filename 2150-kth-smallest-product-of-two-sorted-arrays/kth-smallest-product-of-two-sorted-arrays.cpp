class Solution {
public:
    bool check(vector<int>& nums1, int neg1, vector<int>& nums2, int neg2, long long val, long long& k){
        long long ans = 0;
        int i = neg1;
        int j = 0;
        // neg to neg
        while(i>=0 && j<=neg2){
            if(1LL*nums1[i]*nums2[j]<val){
                ans += neg2 - j + 1;
                i--;
            }
            else j++;
        }

        // pos to pos
        i = neg1+1;
        j = nums2.size()-1;
        while(i<nums1.size() && j>neg2){
            if(1LL*nums1[i]*nums2[j]<val){
                ans += j - neg2;
                i++;
            }
            else j--;
        }

        // neg to pos
        i = 0;
        j = neg2+1;
        while(i<=neg1 && j<nums2.size()){
            if(1LL*nums1[i]*nums2[j]<val){
                ans += nums2.size() - j ;
                i++;
            }
            else j++;
        }

        // pos to neg
        i = nums1.size()-1;
        j = neg2;
        while(i>neg1 && j>=0){
            if(1LL*nums1[i]*nums2[j]<val){
                ans += j + 1;
                i--;
            }
            else j--;
        }

        return ans<k;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int nl1 = -1;
        for(int i=0; i<nums1.size(); i++){
            if(nums1[i]<0) nl1 = i;
            else break;
        }
        int nl2 = -1;
        for(int i=0; i<nums2.size(); i++){
            if(nums2[i]<0) nl2 = i;
            else break;
        }

        long long l = -1e10;
        long long r = 1e10;
        long long ans = l;
        while(l<=r){
            long long m = l + (r - l)/2;
            if(check(nums1, nl1, nums2, nl2, m, k)){
                ans = m;
                l = m+1;
            }
            else r = m-1;
        }
        return ans;
    }
};