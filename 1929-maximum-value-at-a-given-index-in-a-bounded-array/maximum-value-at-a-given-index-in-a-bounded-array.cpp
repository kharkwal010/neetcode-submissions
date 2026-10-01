class Solution {
public:
    long long calc(int n, int a){
        if(n==0) return 0;
        int extra = 0;
        if(n > a){
            extra = n - a;
            n = a;
        }
        long long main = ((long long)n * (2*a + 1 - n))/2;
        return main + extra;
    }
    int maxValue(int n, int index, int maxSum) {
        int l = ceil((double)maxSum/n);
        int r = maxSum;
        int ans = l;
        while(l<=r){
            int m = l + (r - l)/2;
            long long left = calc(index, m-1);
            long long right = calc(n - index - 1, m-1);
            // cout<<m<<" "<<left<<" "<<right<<endl;
            if(left+right+m<=(long long)maxSum){
                ans = m;
                l = m+1;
            }
            else r = m-1;
        }
        return ans;
    }
};