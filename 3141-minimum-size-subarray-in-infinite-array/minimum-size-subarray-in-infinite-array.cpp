class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long sum = 0;
        for(int n: nums) sum += n;
        int extra = target/sum;
        target = target%sum;
        vector<int> terms = nums;
        for(int n: nums) terms.push_back(n);
        int l = 0;
        long long curr = 0;
        int ans = INT_MAX;
        for(int r=0; r<terms.size(); r++){
            curr = curr + terms[r];
            while(curr>target){
                curr -= terms[l];
                l++;
            }
            if(curr==target) ans = min(ans, r-l+1);
        }
        if(ans==INT_MAX) return -1;
        return extra * nums.size() + ans;

    }
};