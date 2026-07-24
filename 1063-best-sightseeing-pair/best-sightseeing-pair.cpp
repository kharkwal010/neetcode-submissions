class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi = values[0];
        int ans = 0;
        for(int i=1; i<values.size(); i++){
            ans = max(ans, maxi + values[i] - 1);
            maxi = max(maxi-1, values[i]);
        }
        return ans;

    }
};