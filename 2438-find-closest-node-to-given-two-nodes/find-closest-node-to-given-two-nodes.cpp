class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<bool> visited1(n, false);
        vector<bool> visited2(n, false);
        while(node1!=-1 || node2!=-1){
            if(node1!=-1) visited1[node1] = true;
            if(node2!=-1) visited2[node2] = true;
            int ans = INT_MAX;
            if(node2!=-1 && visited1[node2]) ans = min(node2, ans);
            if(node1!=-1 && visited2[node1]) ans = min(ans, node1);
            if(ans!=INT_MAX) return ans;

            if(node1==-1 || edges[node1]==-1 || visited1[edges[node1]]) node1 = -1;
            else node1 = edges[node1];

            if(node2==-1 || edges[node2]==-1 || visited2[edges[node2]]) node2 = -1;
            else node2 = edges[node2];
        }
        return -1;

        
    }
};