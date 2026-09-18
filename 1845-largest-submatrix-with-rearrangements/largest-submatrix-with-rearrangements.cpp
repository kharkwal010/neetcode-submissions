class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0; i<n; i++){
            int prev = 0;
            for(int j=0; j<m; j++){
                if(matrix[j][i]==0){
                    prev = 0;
                }
                else{
                    prev++;
                    matrix[j][i]=prev;
                }
            }
        }
        int ans = 0;
        for(int i=0; i<m; i++){
            sort(matrix[i].rbegin(), matrix[i].rend());
            for(int j=0; j<n; j++){
                ans = max(ans, matrix[i][j]*(j+1));
            }
        }
        return ans;
    }
};