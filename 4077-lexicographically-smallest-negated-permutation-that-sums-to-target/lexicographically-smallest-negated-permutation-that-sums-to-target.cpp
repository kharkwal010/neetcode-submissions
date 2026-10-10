class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long sum = ((long long)n * (n+1)) / 2;
        // cout<<(target<(-1*sum))<<endl;
        if(target>sum || target<(-1*sum)) return {};
        // cout<<sum<<endl;
        if(sum%2 != abs(target)%2) return {};
        long long find = (sum - target)/2;
        vector<int> ans;
        for(int i=n; i>0; i--){
            if(i<=find){
                ans.push_back(-1*i);
                find -= i;
            }
            else ans.push_back(i);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};