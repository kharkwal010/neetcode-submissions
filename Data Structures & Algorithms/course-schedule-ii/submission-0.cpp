class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto& num : prerequisites){
            indegree[num[0]]++;
            adj[num[1]].push_back(num[0]);
        }
        queue <int> queue;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                queue.push(i);
            }
        }
        vector<int> answer;
        vector<int> option;
        while(queue.size()!=0){
            int a = queue.front();
            queue.pop();
            answer.push_back(a);
            for (int ad : adj[a]){
                indegree[ad]--;
                if(indegree[ad]==0){
                    queue.push(ad);
                }
            }
        }
        if (answer.size()==numCourses){
            return answer;
        }
        return option;

        
    }
};
