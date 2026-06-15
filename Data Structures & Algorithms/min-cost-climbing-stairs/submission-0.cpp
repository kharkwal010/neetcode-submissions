class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int last = cost.size();
      
        int two = cost[last-1];
        int one = cost[last-2];
        int curr;
        for(int i=last-3; i>=0; i--){
            curr = min( cost[i]+ two , cost[i]+ one);
            two = one;
            one = curr;
        }
        return min(one, two);
        
    }
};
