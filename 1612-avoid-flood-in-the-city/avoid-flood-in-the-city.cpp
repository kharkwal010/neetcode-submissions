class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        set<int> dry;
        unordered_map<int, int> last;
        for(int i=0; i<rains.size(); i++){
            if(rains[i]==0) dry.insert(i);
            else{
                if(last.count(rains[i])){
                    auto it = dry.lower_bound(last[rains[i]]);
                    if(it==dry.end()) return {};
                    else{
                        int d = *it;
                        ans[d] = rains[i];
                        dry.erase(d);
                    }
                }
                last[rains[i]] = i;
            } 
        }
        for(int d: dry) ans[d] = 1;
        return ans;
    }
};