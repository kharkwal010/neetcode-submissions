class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int curr = 0;
        int ans = 0;
        for(int t: target){
            ans += max(0, t - curr);
            curr = t;
        }
        return ans;
    }
};