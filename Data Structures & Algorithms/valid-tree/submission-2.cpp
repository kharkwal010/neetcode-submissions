class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> layer(n,-1);
        layer[0]=0;
        for (int i=0; i<edges.size(); i++){
            int one = edges[i][0];
            int two = edges[i][1];
            int mini = min(one, two);
            int maxi = max(one,two);
            int unknown;
            int known;
            if(layer[maxi]!=-1 && layer[mini]!=-1){
                return false;
            }
            if((layer[maxi]==-1 && layer[mini]==-1)){
                return false;
            }
            if(layer[maxi]==-1 && layer[mini]!=-1){
                unknown =maxi;
                known =mini;
            }
            else{
                unknown =mini;
                known = maxi;
            }
            layer[unknown]=layer[known]+1;
            
        }
        return true;
    }
};
