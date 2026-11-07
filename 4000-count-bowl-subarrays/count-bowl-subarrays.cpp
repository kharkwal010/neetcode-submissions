class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        vector<int> left = nums;
        vector<int> right = nums;
        for(int i=1; i<nums.size(); i++){
            left[i] = max(left[i], left[i-1]);
        }
        for(int i=nums.size()-2; i>=0; i--){
            right[i] = max(right[i+1], right[i]);
        }
        int ans = 0;
        for(int i=1; i<nums.size()-1; i++){
            // cout<<left[i-1]<<" "<<nums[i] <<" "<< right[i+1]<<endl;
            if((left[i-1] > nums[i]) && (right[i+1] > nums[i])) ans++;
        }
        return ans;
    }
};