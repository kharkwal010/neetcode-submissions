class Solution {
public:
    unordered_map<int, int> terms;
    void remove(vector<int>& nums, int l, int r){
        for(int i=l; i<=r; i++){
            terms[nums[i]]--;
        }
        return;
    }
    int maxSubarray(vector<int>& nums) {
        int r=0;
        int l=0;
        int ans = 0;
        while(r<nums.size()){
            int temp = l;
            for(int i=temp; i<r; i++){
                int one = nums[r] + nums[i];
                int two = abs(nums[r] - nums[i]);
                if((one==nums[i] && terms[one]>1) || (one!=nums[i] && terms[one]>0)){
                    // cout<<nums[r]<<" "<<one<<endl;
                    remove(nums, l, i);
                    l=i+1;
                }
                else if((two==nums[i] && terms[two]>1) || (two!=nums[i] && terms[two]>0)){
                    // cout<<nums[r]<<" "<<two<<endl;
                    remove(nums, l, i);
                    l = i+1;
                }
            }
            terms[nums[r]]++;
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};