class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto pre: prerequisites){
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }  
        queue<int> queue;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                queue.push(i);
            }
        }
        vector<int> ans;
        int finish =0;
        while(!(queue.empty())){
            int curr = queue.front();
            finish++;
            ans.push_back(curr);
            queue.pop();
            for(int a: adj[curr]){
                indegree[a]--;
                if(indegree[a]==0){
                    queue.push(a);
                }
            }
        }
        if(finish==numCourses){
            return ans;
        }
        return {};      
    }
};
