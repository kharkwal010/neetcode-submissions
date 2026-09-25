class Solution {
public:
    bool check(string& s, string& t){
        int count = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]!=t[i]){
                count++;
                if(count>2) return false;
            }
        }
        return true;
    }
    vector<int> parent;
    int find(int a){
        if(parent[a]==a) return a;
        return parent[a] = find(parent[a]);
    }

    bool unite(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px==py) return false;
        parent[px]= py;
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(find(i)==find(j)) continue;
                if(check(strs[i], strs[j])) unite(i, j);
            }
        }
        unordered_set<int> groups;
        for(int i=0; i<n; i++){
            groups.insert(find(i));
        }
        return (int)groups.size();

    }
};