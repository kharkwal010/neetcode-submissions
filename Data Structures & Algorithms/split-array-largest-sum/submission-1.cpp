class Solution {
public:
    bool check(vector<int>& nums, int k, long long target){
        long long sum = 0;
        int count = 0;
        for(int n: nums){
            sum+=n;
            if(sum>target){
                sum=n;
                count++;
            }
        }
        if(count<k) return true;
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        long long sum=0;
        int l = 0;
        for(int n: nums){
            sum+=n;
            l = max(l, n);
        }
        long long r = sum;
        while(l<r){
            long long m = l + (r-l)/2;
            cout<<m<<endl;
            if(check(nums, k, m)) r = m;
            else l = m+1;
        }
        return l;

    }
};