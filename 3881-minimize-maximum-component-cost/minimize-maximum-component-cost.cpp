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
        if(pa==pb) return false;
        parent[pa] = pb;
        return true;
    }

    int minCost(int n, vector<vector<int>>& edges, int k) {
       parent.resize(n);
       for(int i=0; i<n; i++) parent[i] = i;
       int comp = n;
       sort(edges.begin(), edges.end(), [](auto& a, auto& b){
            return a[2]<b[2];
       });

       int i=0;
       int ans = 0;
       while(comp>k){
            if(merge(edges[i][0], edges[i][1])) comp--;
            ans = edges[i][2];
            i++;
       }
       return ans;
    }
};