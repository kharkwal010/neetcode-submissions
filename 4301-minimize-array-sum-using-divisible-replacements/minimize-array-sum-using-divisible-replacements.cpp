class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxi+1,0);
        for(int n: nums) freq[n]++;
        for(int i=0; i<maxi; i++){
            if(freq[i]==0) continue;
            for(long long j = 2LL*i; j<=maxi; j+=i){
                freq[i] += freq[j];
                freq[j] = 0;
            }
        }
        long long ans = 0;
        for(int i=1; i<=maxi; i++){
            ans += 1LL*i*freq[i];
        }
        return ans;
    }
};