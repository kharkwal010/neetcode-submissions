class dsu{
public:
    vector<int> parent;
    vector<int> size;
    dsu(int n){
        parent.resize(n, 0);
        size.resize(n, 1);
        for(int i=0; i<n; i++) parent[i] = i;
    }
    int find(int i){
        if(parent[i]==i) return i;
        return parent[i] = find(parent[i]);
    }

    bool merge(int a, int b){
        int pa = find(a);
        int pb = find(b);
        if(pa==pb) return false;
        if(size[pa]>=size[pb]){
            size[pa]+=size[pb];
            parent[pb] = pa;
        }
        else{
            size[pb] += size[pa];
            parent[pa] = pb;
        }
        return true;
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        dsu terms(n);
        for(auto& ele: pairs){
            terms.merge(ele[0], ele[1]);
        }
        unordered_map<int, vector<int>> groups;
        for(int i=0; i<n; i++){          
            int p = terms.find(i);
            groups[p].push_back(i);
        }
        for(auto& ele: groups){
            vector<char> cluster;
            vector<int> index;
            for(int& t: ele.second){
                index.push_back(t);
                cluster.push_back(s[t]);
            }
            sort(index.begin(), index.end());
            sort(cluster.begin(), cluster.end());
            int j=0;
            for(int& i: index){
                s[i] = cluster[j];
                j++;
            }
        }
        return s;
    }
};