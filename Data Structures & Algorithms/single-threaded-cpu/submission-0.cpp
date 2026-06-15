class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        for(int i=0; i<tasks.size(); i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        int time = 0;
        int i=0;
        while(i<tasks.size()){
            if(minheap.empty()){
                time = max(tasks[i][0], time);
                minheap.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            while(i<tasks.size() && tasks[i][0]<=time){
                minheap.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            auto top = minheap.top();
            ans.push_back(top[1]);
            time = time + top[0];
            minheap.pop();
        }
        while(!minheap.empty()){
            auto top = minheap.top();
            ans.push_back(top[1]);
            minheap.pop();
        }
        return ans;
    }
};