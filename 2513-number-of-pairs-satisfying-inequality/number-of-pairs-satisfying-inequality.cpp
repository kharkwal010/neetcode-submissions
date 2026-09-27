class Solution {
public:
    long long ans = 0;
    void merge(vector<int>& nums, int l, int m, int r, int diff){
        int l1 = l;
        int r1 = m;
        int l2 = m+1;
        int r2 = r;
        int j = l2;
        for(int i=l1; i<=r1; i++){
            int curr = nums[i];
            while(j<=r2 && nums[j]<curr-diff) j++;
            if(j>r2) break;
            ans += r2 - j + 1;
        }
        vector<int> temp;
        int i = l1;
        j = l2;
        while(i<=r1 || j<=r2){
            if(i>r1){
                temp.push_back(nums[j]);
                j++;
            }
            else if(j>r2){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                if(nums[i]<nums[j]){
                    temp.push_back(nums[i]);
                    i++;
                }
                else{
                    temp.push_back(nums[j]);
                    j++;
                }
            }
        }
        for(int k=0; k<temp.size(); k++){
            nums[l+k] = temp[k];
        }
        return;
    }

    void merges(vector<int>& nums, int l, int r, int& diff){
        if(l>=r) return;
        int m = l + (r-l) / 2;
        merges(nums, l, m, diff);
        merges(nums, m+1, r, diff);

        merge(nums, l, m, r, diff);

    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        for(int i=0; i<nums1.size(); i++){
            nums1[i] = nums1[i] - nums2[i];
        }
        merges(nums1, 0, nums1.size()-1, diff);
        return ans;

    }
};