class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
       vector<vector<int>> bottomup = mat;
       vector<vector<int>> topdown = mat;
       for(int i=m-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                if(bottomup[i][j]==1) bottomup[i][j] = 1 + min({bottomup[i+1][j], bottomup[i][j+1], bottomup[i+1][j+1]});
            }
       }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(topdown[i][j]==1) topdown[i][j] = 1 + min({topdown[i-1][j], topdown[i][j-1], topdown[i-1][j-1]});
            }
       }
       vector<int> rowdown(m, 0);
       vector<int> coldown(n, 0);
       for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            rowdown[i] = max(rowdown[i], bottomup[i][j]);
            coldown[j] = max(coldown[j], bottomup[i][j]);
        }
       }

        vector<int> rowup(m, 0);
        vector<int> colup(n, 0);
       for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            rowup[i] = max(rowup[i], topdown[i][j]);
            colup[j] = max(colup[j], topdown[i][j]);
        }
       }
       int maxi = 0;
       for(int i=m-1; i>=0; i--){
        int temp = rowdown[i];
        rowdown[i] = maxi;
        maxi = max(temp, maxi);
       }
       maxi = 0;
       for(int i=n-1; i>=0; i--){
        int temp = coldown[i];
        coldown[i] = maxi;
        maxi = max(temp, maxi);
       }
       maxi = 0;
       for(int i=0; i<m; i++){
        maxi = max(maxi, rowup[i]);
        rowup[i] = maxi;
       }
        maxi = 0;
       for(int i=0; i<n; i++){
        maxi = max(maxi, colup[i]);
        colup[i] = maxi;
       }
    // for(int i=0; i<m; i++){
    //     cout<<rowdown[i]<<" ";
    //    }
    //    cout<<endl;
    //     for(int i=0; i<m; i++){
    //     cout<<rowup[i]<<" ";
    //    }
       int ans = 0;
       for(int i=0; i<m; i++){
            ans = max(ans, min(rowdown[i], rowup[i]));
       }
        for(int i=0; i<n; i++){
            ans = max(ans, min(coldown[i], colup[i]));
       }
       return ans*ans;
    }
};