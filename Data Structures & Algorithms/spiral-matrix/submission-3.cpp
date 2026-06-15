class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r_start = 0;
        int r_end = matrix[0].size()-1;
        int c_start = 0;
        int c_end = matrix.size()-1;
        vector<int> ans;
        while(r_start <= r_end && c_start <= c_end){
            for(int i=r_start; i<=r_end; i++){
                ans.push_back(matrix[c_start][i]);
            }
            for(int i = c_start+1; i<=c_end; i++){
                ans.push_back(matrix[i][r_end]);                ;
            }
            if(c_start==c_end || r_start == r_end) break;
            for(int i=r_end-1; i>=r_start; i--){
                ans.push_back(matrix[c_end][i]);
            }
            for(int i=c_end-1; i>c_start; i--){
                ans.push_back(matrix[i][r_start]);
            }
            r_start++;
            r_end--;
            c_start++;
            c_end--;
        } 
        return ans;
    }
};
