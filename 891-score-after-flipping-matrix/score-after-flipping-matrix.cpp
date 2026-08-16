class Solution {
public:
    void fliprow(vector<int>& terms){
        for(int i=0; i<terms.size(); i++){
            if(terms[i]==0) terms[i] = 1;
            else terms[i] = 0;
        }
        return;
    }
    void flipcol(vector<vector<int>>& grid, int c){
        int n = grid.size();
        for(int i=0; i<grid.size(); i++){
            if(grid[i][c]==1) grid[i][c] = 0;
            else grid[i][c] = 1;
        }
        return;
    }
    int binary(vector<int>& terms){
        int n = terms.size();
        int ans = 0;
        int j=0;
        for(int i=n-1; i>=0; i--){
            ans = ans + terms[i] * pow(2, j);
            j++;
        }
        return ans;
    }
    int matrixScore(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++){
            if(grid[i][0]==0){
                fliprow(grid[i]);
            }
        }
        int n = grid.size();
        for(int j=1; j<grid[0].size(); j++){
            int count = 0;
            for(int i=0; i<grid.size(); i++){
                count += grid[i][j];
            }
            if(count<(n+1)/2) flipcol(grid, j);
        }

        // for(int i=0; i<grid.size(); i++){
        //     for(int j=0; j<grid[0].size(); j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            int term = binary(grid[i]);
            ans += term;
        }
        return ans;
    }
};