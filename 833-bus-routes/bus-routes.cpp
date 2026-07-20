class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        unordered_map<int, vector<int>> bus;
        for(int i=0; i<routes.size(); i++){
            for(int ele: routes[i]) bus[ele].push_back(i);
        }
        unordered_set<int> nodes;
        unordered_set<int> lanes;
        queue<int> q;
        for(int ele: bus[source]){
            lanes.insert(ele);
            for(int n: routes[ele]){
                if(nodes.count(n)) continue;
                nodes.insert(n);
                q.push(n);
            }
        }
        int ans = 1;
        while(!q.empty()){
            vector<int> buses;
            while(!q.empty()){
                int top = q.front();
                if(top==target) return ans;
                q.pop();
                for(int ele: bus[top]){
                    if(lanes.count(ele)) continue;
                    lanes.insert(ele);
                    buses.push_back(ele);
                }                
            }
            for(int ele: buses){
                for(int n: routes[ele]){
                    if(nodes.count(n)) continue;
                    nodes.insert(n);
                    q.push(n);
            }
        }
         ans++;   
        }
        return -1;
    }
};  
