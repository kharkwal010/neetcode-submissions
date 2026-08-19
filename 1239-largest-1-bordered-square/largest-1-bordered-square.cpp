class Solution {
public:
    vector<vector<int>> ver;
    vector<vector<int>> hori;
bool check(int len, int i, int j) {

    int top = i - len + 1;
    int left = j - len + 1;

    // Bottom border
    if (hori[i][j] - (left > 0 ? hori[i][left-1] : 0) != len)
        return false;

    // Right border
    if (ver[i][j] - (top > 0 ? ver[top-1][j] : 0) != len)
        return false;

    // Top border
    if (hori[top][j] - (left > 0 ? hori[top][left-1] : 0) != len)
        return false;

    // Left border
    if (ver[i][left] - (top > 0 ? ver[top-1][left] : 0) != len)
        return false;

    return true;
}
    int largest1BorderedSquare(vector<vector<int>>& grid) {        
        hori = grid;
        ver = grid;
        bool present = false;
        for(int i=0; i<grid.size(); i++){
            int sum = 0;
            for(int j=0; j<grid[0].size(); j++){
                sum += grid[i][j];
                hori[i][j] = sum;
            }
            if(sum>0) present = true;
        }
        if(!present) return 0;
        for(int i=0; i<grid[0].size(); i++){
            int sum = 0;
            for(int j=0; j<grid.size(); j++){
                sum += grid[j][i];
                ver[j][i] = sum;
            }
        }
        int ans = 0;
        for(int i=grid.size()-1; i>=0; i--){
            for(int j=grid[0].size()-1; j>=0; j--){
                int r = min(hori[i][j], ver[i][j]);
                int l = ans+1;
                for(int k = r; k>=l; k--){
                    if(check(k, i, j)){
                        ans = k;
                        break;
                    }
                }
            }
        }
        // if(ans==0) return 1;
        return ans*ans;
    }
};