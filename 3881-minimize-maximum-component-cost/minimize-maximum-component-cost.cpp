class Solution {
public:
    vector<int> parent;
    int find(int n){
        if(parent[n]==n) return n;
        return parent[n] = find(parent[n]);
    }
    bool merge(int a, int b){
        int pa = find(a);
        int pb = find(b);
        // cout<<"parents:" <<pa<<" "<<pb<<endl;
        if(pa==pb) return false;
        parent[pa] = pb;
        return true;
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
        sort(edges.begin(), edges.end(), [](auto& a, auto& b){
            return a[2]<b[2];
        });
        int comp = n;
        int ans = 0;
        int i=0;
        while(comp>k && i<edges.size()){
            int a = edges[i][0];
            int b = edges[i][1];
            ans = edges[i][2];
            if(merge(a, b)) comp--;
            // cout<<comp<<" "<<ans<<endl; 
            i++; 
        }
        return ans;
    }
};