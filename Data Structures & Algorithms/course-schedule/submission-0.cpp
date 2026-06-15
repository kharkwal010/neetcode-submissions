class Solution {
public:
    bool canFinish(int numcourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numcourses, 0);
        vector<vector<int>> adj(numcourses);
        for (auto& pre : prerequisites){
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }
        queue<int> queue;
        int finish=0;
        
        for (int i=0; i<numcourses; i++){
            if (indegree[i]==0){
                queue.push(i);
            }
        }
        while (queue.size()!=0){
            int element = queue.front();
            finish++;
            queue.pop();
            for (int ad : adj[element]){
                indegree[ad]--;
                if (indegree[ad]==0){
                queue.push(ad);
            }
            }
             
        }
        if (finish==numcourses){
            return true;
        }
        return false;
        
    }
};
