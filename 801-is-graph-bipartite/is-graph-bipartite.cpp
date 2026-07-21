class Solution {
public:
    bool bfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& colour, int& curr){
        int j = 0;
        queue<int> q;
        colour[curr] = 1;
        q.push(curr);
        while(!q.empty()){
            int size = q.size();
            int col = j%2;
            for(int i=0; i<size; i++){
                int nde = q.front();
                q.pop();
                if(visited[nde]) continue;
                visited[nde] = true;
                for(int nei: graph[nde]){                    
                    if(colour[nei]==-1){
                        colour[nei] = col;
                        q.push(nei);
                    }
                    else if(colour[nei]!=col) return false;
                }
            }
            j++;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        vector<int> colour(graph.size(), -1);
        for(int i=0; i<graph.size(); i++){
            if(visited[i]) continue;
            if(bfs(graph, visited, colour, i)==false) return false;
        }
        return true;
    }
};