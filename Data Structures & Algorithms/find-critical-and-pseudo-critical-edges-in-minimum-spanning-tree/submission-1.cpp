class DSU{
public:
    int n;
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        this->n = n;
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    int find(int node){
        if(parent[node]==node) return node;
        return parent[node] = find(parent[node]);
    }

    bool join(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu==pv) return false;
        if(size[pu]<size[pv]) swap(pu, pv);
        size[pu] += size[pv];
        parent[pv] = pu;
        n--;
        return true;
    }

    bool iscompleted(){
        return n==1;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> terms(edges.size());
       for(int i=0; i<edges.size(); i++){
            terms[i] = {edges[i][2], edges[i][0], edges[i][1], i};
       }
       sort(terms.begin(), terms.end());
       vector<vector<int>> ans(2);

       int mst_weight = 0;
       DSU original(n);
       for(auto& t: terms){
            int one = t[1];
            int two = t[2];
            bool join = original.join(one, two);
            if(join) mst_weight += t[0];
       }
        for(int i=0; i<terms.size(); i++){
            DSU curr(n);
            int weight = 0;
            for(int j=0; j<terms.size(); j++){
                if(i==j) continue;
                int one = terms[j][1];
                int two = terms[j][2];
                bool join = curr.join(one, two);
                if(join) weight += terms[j][0];
            }
            if(!curr.iscompleted() || weight!=mst_weight){
                ans[0].push_back(terms[i][3]);
                continue;
            }

            DSU sec(n);
            weight = terms[i][0];
            sec.join(terms[i][1], terms[i][2]);
            for(int j=0; j<terms.size(); j++){
                if(i==j) continue;
                int one = terms[j][1];
                int two = terms[j][2];
                bool join = sec.join(one, two);
                if(join) weight += terms[j][0];
            }
            if(weight==mst_weight){
                ans[1].push_back(terms[i][3]);
                
            }

        }
       // critical edge: if edge nhi rhe to mst ka weight bd jayega

       //psuedo critical edge: if edge rhe to mst unta hi aayega, and should not be critical


        return ans;
    }
};