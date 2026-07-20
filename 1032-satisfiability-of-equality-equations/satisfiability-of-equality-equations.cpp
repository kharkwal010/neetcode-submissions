class Solution {
public:
    vector<int> parent;
    int find(int i){
        if(parent[i]==i) return i;
        return parent[i] = find(parent[i]);
    }
    bool join(int i, int j){
        int pi = find(i);
        int pj = find(j);
        if(pi==pj) return true;
        parent[pi] = pj;
        return false;
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26,0);
        for(int i=0; i<26; i++){
            parent[i] = i;
        }
        for(int i=0; i<equations.size(); i++){
            if(equations[i][1]!='!'){
                int one = equations[i][0]-'a';
                int two = equations[i][3]-'a';
                join(one, two);
            }
        }
        for(int i=0; i<equations.size(); i++){
            if(equations[i][1]!='='){
                int one = find(equations[i][0]-'a');
                int two = find(equations[i][3]-'a');
                if(one==two) return false;
            }
        }
        return true;
    }
};