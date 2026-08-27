class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        int ans = 0;        
        int j = 0;
        int covered = 0;
        int i = 0;
        while(j<tiles.size() && i<tiles.size()){
            int st = tiles[i][0];
            int end = st + carpetLen - 1;
            int partial = 0;
            while(j<tiles.size() && tiles[j][0]<=end){
                if(tiles[j][1]<=end){
                    covered += (tiles[j][1] - tiles[j][0] + 1);
                }
                else{
                    partial = (end-tiles[j][0]+1);
                    break;
                }
                j++;
            }
            ans = max(ans, covered + partial);
            if(i==j) break;
            covered -= (tiles[i][1] - tiles[i][0] + 1);
            i++;
        }
        return ans;
        
    }
};