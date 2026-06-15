class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startr = 0;
        int startc = 0;
        int endc = matrix[0].size() - 1;
        int endr = matrix.size() - 1;
        vector<int> ans;
        while(startr<=endr && startc<=endc){
            for(int i=startc; i<=endc; i++) ans.push_back(matrix[startr][i]);
            for(int i=startr+1; i<=endr; i++) ans.push_back(matrix[i][endc]);
            if(startr==endr || startc==endc) break;
            for(int i=endc-1; i>=startc; i--) ans.push_back(matrix[endr][i]);
            for(int i=endr-1; i>=startr+1; i--) ans.push_back(matrix[i][startr]);
            startr++;
            startc++;
            endr--;
            endc--;
        }
        return ans;
    }
};
