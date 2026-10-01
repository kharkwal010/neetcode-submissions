class Solution {
public:  
    vector<int> length;
    int helper(vector<int>& cost, int target){
        if(target==0) return 0;
        if(target<0) return INT_MIN;
        if(length[target]!=-1) return length[target];
        int ans = INT_MIN;
        for(int i=0; i<9; i++){
            ans = max(ans, 1+helper(cost, target - cost[i]));
        }
        return length[target] = ans;
    }
    string largestNumber(vector<int>& cost, int target) {
        length.resize(target+1, -1);
        int maxi = helper(cost, target);
        if(maxi<=0) return "0";
        string ans = "";
        // for(int t: length) cout<<t<<" ";
        while(maxi>=0){
            for(int i=8; i>=0; i--){
                if(target-cost[i]<0) continue;
                if(length[target-cost[i]]==maxi-1){
                    ans.push_back('0' + i + 1);
                    target = target - cost[i];
                    break;
                }
            }
            maxi--;
        }
        return ans;
    }
};