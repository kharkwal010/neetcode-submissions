class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        //all second best - min second best + global min;
        if(units[0].size()==1){
            long long res = 0;
            for(auto ele: units) res += ele[0];
            return res;
        }
        int mini = INT_MAX;
        int smini = INT_MAX;
        long long ans = 0;
        for(auto& nums: units){
            int one = INT_MAX;
            int two = INT_MAX;
            for(int n: nums){
                if(n<one){
                    two = one;
                    one = n;
                }
                else if(n<two){
                    two = n;
                }
            }
            ans += two;
            mini = min(mini, one);
            smini = min(smini, two);
        }
        return ans - smini + mini;
    }
};