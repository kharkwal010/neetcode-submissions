class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        vector<long long> prefix;
        prefix.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
            prefix.push_back(prefix.back() + nums[i]);
        }
        long long sum = prefix[nums.size()-1];
        int n = prefix.size();
        int j = 1;
        int k = 1;
        int i=0;
        int mod = 1e9+7;
        long long ans = 0;
        while(i<n-2 && prefix[i]<=sum/3){
            long long tar = sum - prefix[i];
            long long low = 2*prefix[i];
            long long high = prefix[i] + tar/2;
            while(j<n && (j<=i || prefix[j]<low)){
                j++;
            }
            while(k<n-1 && (k<j || prefix[k]<=high)){
                k++;
            }
            ans = (ans + (k - j));
            i++;

        }
        return ans%mod;

    }
};