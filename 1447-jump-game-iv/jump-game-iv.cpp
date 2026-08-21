class Solution {
public:
    int minJumps(vector<int>& arr) {
        vector<bool> visited(arr.size(), false);
        unordered_map<int, vector<int>> index;
        for(int i=0; i<arr.size(); i++){
            index[arr[i]].push_back(i);
        }
        int count = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int curr = q.front();
                if(curr==arr.size()-1) return count;
                q.pop();
                if(curr-1>=0 && !visited[curr-1]){
                    // visited[curr-1] = true;
                    q.push(curr-1);
                }
                if(curr+1<arr.size() && !visited[curr+1]){
                    // visited[curr+1] = true;
                    q.push(curr+1);
                }
                if(!visited[curr]){
                    for(int e: index[arr[curr]]){
                        visited[e] = true;
                        // cout<<e<<" ";
                        q.push(e);
                    }
                }
            }
            // cout<<endl;
            count++;
        }
        return -1;

    }
};