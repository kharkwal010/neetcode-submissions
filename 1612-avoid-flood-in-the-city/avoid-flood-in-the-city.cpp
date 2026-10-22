class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(), -1);
        set<int> power;
        unordered_map<int, int> present;
        for(int i=0; i<rains.size(); i++){
            if(rains[i]==0){
                power.insert(i);
                continue;
            }
            if(present.count(rains[i])){
                int last = present[rains[i]];
                auto it = power.lower_bound(last);
                if(it==power.end()) return {};
                int j = *it;
                ans[j] = rains[i];
                power.erase(j);
            }
            present[rains[i]] = i;
            
       }
       for(int e: power) ans[e] = 1;
       return ans;
    }
};