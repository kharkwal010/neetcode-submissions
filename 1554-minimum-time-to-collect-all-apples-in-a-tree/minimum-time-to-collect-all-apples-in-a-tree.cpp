class Solution {
public:
    vector<vector<int>> adj;
    int apple(vector<bool>& having, int curr, int parent){
        int count = 0;
        for(int nei: adj[curr]){
            if(nei==parent) continue;
            int next_apple = apple(having, nei, curr);
            if(next_apple>0 || having[nei]) count += 2 + next_apple;
        }
        return count;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
       adj.resize(n);
       for(auto& ed: edges){
        adj[ed[0]].push_back(ed[1]);
        adj[ed[1]].push_back(ed[0]);
       }
        return apple(hasApple, 0, -1);
    }
};