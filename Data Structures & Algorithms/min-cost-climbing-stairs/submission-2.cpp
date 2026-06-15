class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        
        int two = cost[len-1];
        int one = cost[len-2];
        for(int i= len-3; i>=0; i--){
            int curr = cost[i] + min(one, two);
            two = one;
            one = curr;
        }
        return min(one, two);
    }
};
