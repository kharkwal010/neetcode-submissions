class DSU {
public:
    int n;
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        this->n = n;
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0; i<parent.size(); i++){
            parent[i] = i;
        }
    }
    int find(int a){
        if(parent[a]==a) return a;
        return parent[a] = find(parent[a]);
    }

    bool unionset(int a, int b){
        int pa = find(a);
        int pb = find(b);
        if(pa==pb) return false;
        if(size[pa]>=size[pb]){
            size[pa] += size[pb];
            parent[pb] = pa;
        }
        else{
            size[pb] += size[pa];
            parent[pa] = pb;
        }
        return true;
    }

    bool complete(){
        if(*max_element(size.begin(), size.end())==n) return true;
        return false;
    }
};
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
          //basic mst weight;
          for(int i=0; i<edges.size(); i++){
            edges[i].push_back(i);
          }
          sort(edges.begin(), edges.end(), [](auto& x, auto& y){
            return x[2]<y[2];
          });
          int mst_weight = 0;
          DSU first(n);
          for(auto ed: edges){
            if(!first.unionset(ed[0], ed[1])) continue;
                mst_weight += ed[2];
          }
          
          vector<vector<int>> ans(2);
          
            for(int i=0; i<edges.size(); i++){
                DSU critical(n);
                int mst = 0;
                for(int j=0; j<edges.size(); j++){
                    if(j==i) continue;
                    if(!critical.unionset(edges[j][0], edges[j][1])) continue;
                    mst += edges[j][2];
                }
                if(!critical.complete() || mst > mst_weight){
                    ans[0].push_back(edges[i][3]);
                    continue;
                }
                DSU psuedo(n);
                mst = edges[i][2];
                psuedo.unionset(edges[i][0], edges[i][1]);
                for(int j=0; j<edges.size(); j++){
                    if(j==i) continue;
                    if(!psuedo.unionset(edges[j][0], edges[j][1])) continue;
                    mst += edges[j][2];
                }
                cout<<mst<<endl;
                if(mst == mst_weight){
                    ans[1].push_back(edges[i][3]);
                }
            }
            return ans;

    }
};