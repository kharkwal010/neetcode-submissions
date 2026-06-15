class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        
        int two = cost[len-1];
        int one = cost[len-2];
        for(int i= len-3; i>=0; i--){
            int temp = one;
            one = min(cost[i]+one, cost[i]+two);
            two = temp;
        }
        return min(one, two);
    }
};
