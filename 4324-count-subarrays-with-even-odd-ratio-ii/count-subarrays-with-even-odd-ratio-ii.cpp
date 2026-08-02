class Solution {
public:
    vector<long long> merge(vector<long long>& nums, int l, int r, long long& ans){
        if(l==r) return {nums[l]};
        int mid = (l+r)/2;
        vector<long long> left = merge(nums, l, mid, ans);
        vector<long long> right = merge(nums, mid+1, r, ans);
        int m = left.size();
        int n = right.size();
        vector<long long> temp;
        int i = 0;
        int j = 0;
        while(i<m || j<n){
            if(j==n){
                temp.push_back(left[i]);
                i++;
            }
            else if(i==m){
                temp.push_back(right[j]);
                j++;
            }
            else if(left[i]<=right[j]){
                temp.push_back(left[i]);
                ans += n - j;
                i++;
            }
            else{
                temp.push_back(right[j]);
                j++;
            }
        }
        // cout<<ans<<endl;
        return temp;
    }
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        long long ans = 0;
        vector<long long> prefix(nums.size()+1, 0);
        for(int i=0; i<nums.size(); i++){
            int curr = (nums[i]%2==0) ? -b : a;
            prefix[i+1] += curr + prefix[i];
        }
        merge(prefix, 0, prefix.size()-1, ans);
        return ans;
    }
};