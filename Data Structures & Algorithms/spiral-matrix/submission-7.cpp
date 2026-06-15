class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rs = 0;
        int re = matrix[0].size()-1;
        int cs = 0;
        int ce = matrix.size()-1;
        vector<int> ans;

        while(true){
            for(int i=rs; i<=re; i++){
                ans.push_back(matrix[cs][i]);
            }
            if(cs==ce) break;
            for(int i=cs+1; i<=ce; i++){
                ans.push_back(matrix[i][re]);
            }
            if(rs==re) break;
            for(int i=re-1; i>=rs; i--){
                ans.push_back(matrix[ce][i]);
            }
            if(cs==ce-1) break;
            for(int i=ce-1; i>=cs+1; i--){
                ans.push_back(matrix[i][rs]);
            }
            if(rs==re-1) break;
            rs++;
            cs++;
            re--;
            ce--;
        }
        return ans;
    }
};
