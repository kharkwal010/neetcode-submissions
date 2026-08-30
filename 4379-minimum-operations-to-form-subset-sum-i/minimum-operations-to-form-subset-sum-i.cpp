class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        vector<int> dp(sum+1, INT_MAX);
        dp[0] = 0;
        for(int n: nums){
            vector<pair<int, int>> terms;
            // divide
            int cnt = 0;
            int term = n;
            while(term>0){
                if(term<=sum) terms.push_back({term, cnt});
                term = term / 2;
                cnt++;
            }

            // multiply
            cnt = 1;
            term = n*2;
            while(term<=sum){
                terms.push_back({term, cnt});
                cnt++;
                term = term * 2;
            }
            vector<int> newdp = dp;
            for(auto[ele, op] : terms){
                // cout<<ele<<" "<<op<<"   ";
                for(int i=0; i<dp.size(); i++){
                    if(dp[i]==INT_MAX) continue;
                    if(i+ele<=sum){
                        newdp[i+ele] = min(newdp[i+ele], dp[i] + op);
                    }
                }
            }
            dp = newdp;
            // for(int ele: dp){
            //     if(ele==INT_MAX) cout<<"i ";
            //     else cout<<ele<<" ";
            // }
            // cout<<endl;
        }
        return (dp[sum]==INT_MAX) ? -1 : dp[sum];
    }
};