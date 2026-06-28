class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> indegree;
        for(auto ele: roads){
            indegree[ele[0]]++;
            indegree[ele[1]]++;
        }
        priority_queue<int, vector<int>, greater<int>> minheap;
        for(int i=0; i<n; i++){
            minheap.push(indegree[i]);
        }
        int i=1;
        long long sum = 0;
        while(!minheap.empty()){
            sum += (long long)i*minheap.top();
            minheap.pop();
            i++;
        }
        return sum;
    }
};