class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        set<vector<int>> visited;
        int i=0;
        int n = points.size();
        int count = 0;
        while(true){
            int sz = points.size();
            while(i<sz){
                if(points[i]==target) return count;
                for(int j=0; j<i; j++){
                    vector<int> npoint;
                    for(int x=0; x<3; x++){
                        npoint.push_back(floor((points[i][x] + points[j][x])/2.0));
                    }
                    if(visited.count(npoint)) continue;
                    visited.insert(npoint);
                    points.push_back(npoint);
                }
                i++;                
            }
            count++;
            if(points.size()==sz) return -1;
        }
        
    }
};