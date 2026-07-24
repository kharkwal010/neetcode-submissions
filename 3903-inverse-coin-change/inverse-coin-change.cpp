class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();

        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        vector<int> ans;

        for (int coin = 1; coin <= n; coin++) {

            if (dp[coin] == numWays[coin - 1]) {
                continue;
            }

            if (dp[coin] + 1 != numWays[coin - 1]) {
                return {};
            }

            ans.push_back(coin);

            for (int j = coin; j <= n; j++) {
                dp[j] += dp[j - coin];
            }
        }

        return ans;
    }
};