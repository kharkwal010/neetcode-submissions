class Solution {
public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size());
vector<int> indegree(edges.size(),0);
for (auto& edge : edges){
    indegree[edge[0]-1]++;
    indegree[edge[1]-1]++;
    adj[edge[0]-1].push_back(edge[1]-1);
    adj[edge[1]-1].push_back(edge[0]-1);    
}
queue<int> queue;
for (int i=0; i<edges.size(); i++){
    if(indegree[i]==1){
        queue.push(i);
    }
}
while (queue.size()!=0){
    int top = queue.front();
    queue.pop();
    for(int ad : adj[top]){
        indegree[ad]--;
        if (indegree[ad]==1){
            queue.push(ad);
        }
    }    
}
for (int i= edges.size()-1; i>=0; i--){
    int one = edges[i][0]-1;
    int two = edges[i][1]-1;
    if (indegree[one]==2 && indegree[two]==2){
        return {one+1, two+1};
    }
}
    }
};
