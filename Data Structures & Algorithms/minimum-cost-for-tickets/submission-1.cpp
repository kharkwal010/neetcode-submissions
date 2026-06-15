class Solution {
public:
    unordered_map<string, int> memo;
    int price(vector<int>& days, vector<int>& costs, int next, int i){
        if(i>=days.size() || next>days[days.size()-1]) return 0;
        string key = to_string(i) + "," + to_string(next);
        if(memo.count(key)) return memo[key];
        int ans = INT_MAX;
        if(next<days[i]){
            ans = min(ans, costs[0] + price(days, costs, days[i], i+1));
            ans = min(ans, costs[1] + price(days, costs, days[i]+6, i+1));
            ans = min(ans, costs[2] + price(days, costs, days[i]+29, i+1));
        }
        else{
            ans = min(ans, price(days, costs, next, i+1));
        }
        memo[key] = ans;
        return ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return price(days, costs, 0, 0);
    }
};