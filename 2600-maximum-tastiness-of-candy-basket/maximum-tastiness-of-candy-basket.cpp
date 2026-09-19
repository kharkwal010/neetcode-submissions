class Solution {
public:
    bool check(vector<int>& prices, int k, int m){
        int pick = 1;
        long long next = (long long)prices[0] + m;
        for(int i=0; i<prices.size(); i++){
            while(i<prices.size() && prices[i]<next) i++;
            if(i==prices.size()) break;
            pick++;
            if(pick==k) return true;
            next = (long long)prices[i] + m;
        }
        return false;
    }
    int maximumTastiness(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int n = prices.size();
        int r = prices[n-1] - prices[0];
        int l = 0;
        int ans = 0;
        while(l<=r){
            int m = l + (r-l)/2;
            if(check(prices, k, m)){
                ans = m;
                l = m+1;
            }
            else r = m-1;
        }
        return ans;
    }
};