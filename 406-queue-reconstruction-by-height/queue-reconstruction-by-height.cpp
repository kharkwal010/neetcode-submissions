class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        vector<int> remain;
        sort(people.begin(), people.end());
        for(int i=0; i<people.size(); i++){
            remain.push_back(people[i][1]);
            if(people[i][1]==0) minheap.push(people[i]);
        }
        while(!minheap.empty()){
            auto top = minheap.top();
            minheap.pop();
            ans.push_back(top);
            for(int i=0; i<people.size(); i++){
                if(remain[i]==0) continue;
                if(people[i][0] > top[0]) break;
                remain[i]--;
                if(remain[i]==0) minheap.push(people[i]);
            }
        }
        return ans;
    }
};