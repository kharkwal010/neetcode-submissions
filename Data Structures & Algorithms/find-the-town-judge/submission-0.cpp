class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, unordered_set<int>> trusting;
        for(auto& t: trust){
            trusting[t[0]].insert(t[1]);
        }
        
        int a = INT_MAX;
        for(int t=1; t<=n; t++){
            if(trusting[t].empty()){
                if(a==INT_MAX) a = t;
                else{
                    return -1;
                }
            }
        }
        if(a==INT_MAX) return -1;

        for(auto t: trusting){
            if(t.first!=a && !t.second.count(a)) return -1;
        }
        return a;
    }
};