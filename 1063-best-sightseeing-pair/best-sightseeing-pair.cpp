class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi = values[0];
        int ans = 0;
        for(int i=1; i<values.size(); i++){
            maxi = max(maxi-1, values[i-1]);
            ans = max(ans, values[i] + maxi - 1);
            cout<<maxi<<" ";
        }
        return ans;
    }
};