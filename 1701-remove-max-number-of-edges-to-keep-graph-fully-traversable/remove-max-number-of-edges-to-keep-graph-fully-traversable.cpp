class dsu{
public:
    vector<int> parent;
    vector<int> size;
    int m_size = 1;
    dsu(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++) parent[i] = i;
    }

    int find(int n){
        if(parent[n]==n) return n;
        return parent[n] = find(parent[n]);
    }

    bool merge(int a, int b){
        int pa = find(a);
        int pb = find(b);
        if(pa==pb) return false;
        if(size[pa]>size[pb]){
            size[pa] += size[pb];
            parent[pb] = pa;
            m_size = max(m_size, size[pa]);
        }
        else{
            size[pb] += size[pa];
            parent[pa] = pb;
            m_size = max(m_size, size[pb]);
        }
        return true;
    }
    
    bool complete(){
        return m_size==parent.size();
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        dsu alice(n);
        dsu bob(n);
        sort(edges.rbegin(), edges.rend());
        int count = 0;
        for(vector<int>& ed: edges){
            int type = ed[0];
            int a = ed[1]-1;
            int b = ed[2]-1;
            if(type==3){
                bool one = alice.merge(a, b);
                bool two = bob.merge(a, b);
                if(!( one || two )) count++;
            }
            else if(type==1){
                // cout<<a<<" "<<b<<" "<<alice.merge(a, b)<<endl;
                if(!alice.merge(a, b)) count++;
            }
            else{
                if(!bob.merge(a, b)) count++;
            }
        }
        // cout<<"alice:" << alice.m_size<<endl;
        // cout<<"bob:" <<bob.m_size<<endl;
        if(alice.complete() && bob.complete()) return count;
        return -1;
    }
};