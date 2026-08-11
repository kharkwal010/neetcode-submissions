class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int n = tiles.size();
        sort(tiles.begin(), tiles.end());
        
        queue<pair<int, int>> q;
        int ans = 0;
        int j = 0;
        int val = 0;
        int carry = 0;
        for(int i=0; i<n; i++){
            int curr = tiles[i][0];
            int end = curr+carpetLen-1;         
            while(j<n && tiles[j][1]<=end){
                q.push({tiles[j][0], tiles[j][1]});
                val += (tiles[j][1] - tiles[j][0] + 1);
                j++;
            }
            int extra = 0;
            if(j<n && tiles[j][0]<=end){
                extra = end - tiles[j][0] + 1; 
            }
            // cout<<val<<endl;
            val += extra;
            ans = max(ans, val);     
            val -= extra; 
            val -= (tiles[i][1] - tiles[i][0] + 1);     
            
        }
        return ans;
    }
};