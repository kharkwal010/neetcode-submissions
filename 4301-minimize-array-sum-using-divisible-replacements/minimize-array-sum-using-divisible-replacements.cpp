class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = 0;
        unordered_map<int, int> freq;
        for(int n: nums){
            freq[n]++;
            mini = min(mini, n);
            maxi = max(maxi, n);
        }
        long long sum = 0;
        if(mini==1) return nums.size();
        for(int i=mini; i<=maxi; i++){
            if(freq[i]==0 || !freq.count(i)) continue;
            for(long long j=i*2LL; j<=maxi; j+=i){
                sum += (long long)freq[j]*i;
                freq[j]=0;
            }
        }
        for(int i=mini; i<=maxi; i++) sum+=(long long)freq[i]*i;
        return sum;
    }
};