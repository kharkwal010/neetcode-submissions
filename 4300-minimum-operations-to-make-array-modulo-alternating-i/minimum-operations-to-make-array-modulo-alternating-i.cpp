class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> even(k);
        vector<int> odd(k);
        for(int tar=0; tar<k; tar++){
            int e = 0;
            int o = 0;
            for(int i=0; i<n; i++){
                int mod = nums[i]%k;
                int term = abs(mod-tar);
                term = min(term, k - term);
                if(i%2==0) e+=term;
                else o+=term;
            }
            even[tar] = e;
            odd[tar] = o;
        }
        int ans = INT_MAX;
        for(int i=0; i<k; i++){
            for(int j=0; j<k; j++){
                if(i==j) continue;
                ans = min(ans, even[i] + odd[j]);
            }
        }
        return ans;
    }
};