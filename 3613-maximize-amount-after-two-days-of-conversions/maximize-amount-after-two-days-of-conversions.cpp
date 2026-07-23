class Solution {
public:
    
    unordered_map<string, vector<pair<double, string>>> day2;
    double bfs(string curr, string& target){
        unordered_set<string> visited;
        queue<pair<double, string>> q;
        q.push({1.0, curr});
        visited.insert(curr);
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            string cur = top.second;
            double num = top.first;
            if(cur==target) return num;
            for(auto nei: day2[cur]){
                if(visited.count(nei.second)) continue;
                visited.insert(nei.second);
                q.push({nei.first*num, nei.second});
            }            
        }
        return -1;
    }
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        unordered_map<string, vector<pair<double, string>>> day1;
        for(int i=0; i<pairs1.size(); i++){
            day1[pairs1[i][0]].push_back({rates1[i], pairs1[i][1]});
            day1[pairs1[i][1]].push_back({1/rates1[i], pairs1[i][0]});
        }
        for(int i=0; i<pairs2.size(); i++){
            day2[pairs2[i][0]].push_back({rates2[i], pairs2[i][1]});
            day2[pairs2[i][1]].push_back({1/rates2[i], pairs2[i][0]});
        }
        unordered_set<string> visited1;
        queue<pair<double, string>> q;
        q.push({1.0, initialCurrency});
        visited1.insert(initialCurrency);
        unordered_map<string, double> coins;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            string cur = top.second;
            double num = top.first;
            coins[cur] = num;
            for(auto nei: day1[cur]){
                if(visited1.count(nei.second)) continue;
                visited1.insert(nei.second);
                q.push({nei.first*num, nei.second});
            }            
        }
        double ans = 1;
        for(auto ele: coins){
            ans = max(ans, ele.second*bfs(ele.first, initialCurrency));
        }
        return ans;       

    }
};