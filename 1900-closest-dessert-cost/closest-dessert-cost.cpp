class Solution {
public:
    void dessert(vector<int>& cost, int i, int val, int target, int& ans, int& diff){
       if(i==cost.size() || val>target){
            if(diff>=abs(val-target)){
                if(diff==abs(val-target)){
                    if(val<target) ans = val;
                }
                else{
                    diff = abs(val-target);
                    ans = val;
                }
                
            }
            return;
       }
       dessert(cost, i+1, val, target, ans, diff);
       dessert(cost, i+1, val + cost[i], target, ans, diff);
       dessert(cost, i+1, val+2*cost[i], target, ans, diff);
       return;      
       
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int ans = INT_MAX;
        int diff = INT_MAX;
        for(int base: baseCosts){
            dessert(toppingCosts, 0, base, target, ans, diff);
        }
        return ans;

    }
};