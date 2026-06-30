class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainder;
        remainder[0] = -1;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            int rem = sum%k;
            if(remainder.count(rem) && i-remainder[rem]>=2) return true;
            if(!remainder.count(rem)) remainder[rem] = i;
        }
        return false;
    }
};