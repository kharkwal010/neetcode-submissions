class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto ele: prerequisites){
            adj[ele[1]].push_back(ele[0]);
            indegree[ele[0]]++;
        }
        queue<int> queue;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                queue.push(i);
            }
        }  
        int finish=0;
        vector<int> courses;
        while(!queue.empty()){
            int top = queue.front();
            queue.pop();
            finish++;
            courses.push_back(top);
            for(int nei: adj[top]){
                indegree[nei]--;
                if(indegree[nei]==0){
                    queue.push(nei);
                }
            }
        }
        if(finish!=numCourses){
            return {};
        }
        return courses;

    }
};
