class Solution {
public:
    long long sum(int n, int a){
        if(a<=n){
            int rem = n - a;
            long long s = (1LL*a*(a+1))/2;
            return s + rem;
        }
        long long ans = (1LL*n * (2*a+1-n))/2;
        return ans;
    }
    bool check(int n, int index, long long maxsum, int m){
        int prior = index;
        int post = n - index - 1;
        // cout<<m<<" "<<sum(prior, m-1)<<" "<<sum(post, m-1)<<endl;
        long long s = 1LL * m + sum(prior, m-1) + sum(post, m-1);
        return s<=maxsum;
    }
    int maxValue(int n, int index, int maxSum) {
        int l = 1;
        int r = maxSum;
        int ans = l;
        while(l<=r){
            int m = l + (r - l) / 2;
            if(check(n, index, maxSum, m)){
                ans = m;
                l = m+1;
            }
            else r = m-1;
        }
        return ans;
    }
};