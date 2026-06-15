class Solution {
public:
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<int, unordered_set<int>> same;
        unordered_map<string, int> match;
        for(int i=0; i<accounts.size(); i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(match.count(accounts[i][j])){
                    same[match[accounts[i][j]]].insert(i);
                    same[i].insert(match[accounts[i][j]]);
                }
                match[accounts[i][j]] = i;
            }
        }
        unordered_set<int> visited;
        vector<vector<string>> ans;
        for(int i=0; i<accounts.size(); i++){
            if(visited.count(i)) continue;
            visited.insert(i);
            queue<int> q;
            q.push(i);
            vector<string> layer;
            unordered_set<string> mails;
            layer.push_back(accounts[i][0]);
            while(!q.empty()){
                int j = q.front();
                q.pop();
                for(int k=1; k<accounts[j].size(); k++){
                    if(mails.count(accounts[j][k])) continue;
                    mails.insert(accounts[j][k]);
                    layer.push_back(accounts[j][k]);
                }
                for(int ele: same[j]){
                    if(visited.count(ele)) continue;
                    visited.insert(ele);
                    q.push(ele);
                }
            }
            sort(layer.begin() + 1, layer.end());
            ans.push_back(layer);
        }
        return ans;
        
    }
};