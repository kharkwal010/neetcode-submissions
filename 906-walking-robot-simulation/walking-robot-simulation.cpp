class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> obs;
        int r = 0;
        int c = 0;
        int i = 0;
        int ans = 0;
        for(vector<int> ele: obstacles){
            obs.insert({ele[0], ele[1]});
        }
        for(int com: commands){
            if(com==-2){
                i = (4 + (i - 1))%4;
            }
            else if(com==-1) i = (i+1)% 4;
            else{
                for(int j=1; j<=com; j++){
                    int nr = r + dir[i][0];
                    int nc = c + dir[i][1];
                    if(obs.count({nr, nc})) break;
                    r = nr;
                    c = nc;                
                }
                ans = max(ans, r*r + c*c);
                
            }
        }
        return ans;

        
    }
};