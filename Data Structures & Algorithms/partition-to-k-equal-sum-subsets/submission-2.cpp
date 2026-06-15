class Solution {
public:
    bool part(vector<int>& nums, vector<int> complete, int count, int j, int target){
        if(j==nums.size()){
            if(count==complete.size()) return true;
            return false;
        }
        bool ans = false;
        for(int i=0; i<complete.size(); i++){
            if(complete[i]!=target){
                complete[i]+=nums[j];
                if(complete[i]==target) ans = ans || part(nums, complete, count+1, j+1, target);
                else if(complete[i]<target) ans = ans || part(nums, complete, count, j+1, target);
                complete[i]-=nums[j];
            }
        }
        return ans;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(int& n: nums) sum+=n;
        if(sum%k!=0) return false;
        int target = sum/k;
        sort(nums.rbegin(), nums.rend());
        vector<int> complete(k, 0);
        return part(nums, complete, 0, 0, target);
    }
};