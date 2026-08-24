class Solution {
public:
    int lower(vector<int>& terms, int l, int r, int limit){
        int ans = r + 1;
        while(l<=r){
            int m = (l+r)/2;
            if(terms[m]<limit){
                l = m + 1;
            }
            else{
                // cout<<limit<<" "<<m<<" "<<terms[m]<<endl;
                ans = m;
                r = m - 1;
            }
        }
        return ans;
    }
    int upper(vector<int>& terms, int l, int r, int limit){
        int ans = l-1;
        while(l<=r){
            int m = (l+r)/2;
            if(terms[m]<=limit){
                // cout<<limit<<" "<<m<<" "<<terms[m]<<endl;
                ans = m;
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        return ans;
    }
    int waysToSplit(vector<int>& nums) {
      vector<int> prefix = nums;
      for(int i=1; i<nums.size(); i++) prefix[i] = prefix[i-1] + prefix[i];
        int sum = prefix[nums.size()-1];
        int mod = 1e9+7;
        int l = 0;
        int r = nums.size() - 2;
        long long ans = 0;
        while(l<nums.size()-2 && prefix[l]<=sum/3){
            int llimit = prefix[l]*2;
            int ulimit = prefix[l] + (sum - prefix[l])/2;
            int lb = lower(prefix, l+1, r, llimit);
            int ub = upper(prefix, l+1, r, ulimit);
            int diff = max(0, ub - lb + 1);
            ans = (ans + diff) % mod;
            l++;
        }
        return ans;

    }
};