class Solution {
public:
    void rev(vector<int>& nums, int l, int r){
        while(l<r){
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        int n = nums.size();
        k = k%n;
        rev(nums, 0, k-1);
        rev(nums, k, n-1);

    }
};