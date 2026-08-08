class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<vector<int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
        unordered_map<int, int> row;
        unordered_map<int, int> col;
        unordered_map<int, int> ndia;
        unordered_map<int, int> pdia;
        set<pair<int, int>> bulbs;
        for(auto q: lamps){
            int r = q[0];
            int c = q[1];
            if(bulbs.count({r, c})) continue;
            row[r]++;
            col[c]++;
            pdia[r+c]++;
            ndia[r-c]++;
            bulbs.insert({r, c});
        }
        vector<int> ans;
        for(auto q: queries){
            int r = q[0];
            int c = q[1];
            if(row[r]>0 || col[c]>0 || pdia[r+c]>0 || ndia[r-c]>0) ans.push_back(1);
            else ans.push_back(0);
            if(bulbs.count({r, c})){
                row[r]--;
                col[c]--;
                ndia[r-c]--;
                pdia[r+c]--;
                bulbs.erase({r,c});
            }

            for(int i=0; i<8; i++){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(bulbs.count({nr, nc})){
                    row[nr]--;
                    col[nc]--;
                    ndia[nr-nc]--;
                    pdia[nr+nc]--;
                    bulbs.erase({nr,nc});
                }
            }
        }
        return ans;
    }
};