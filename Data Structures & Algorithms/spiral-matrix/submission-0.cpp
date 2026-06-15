class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        vector<int> ans;
        int number = row * column;
        int start_i = 0;
        int start_j = 0;
        int end_i = column;
        int end_j = row;
        while(number>0){
        int i = start_i;
        int j = start_j;
        while(j<end_i && number>0){
            ans.push_back(matrix[i][j]);
            number--;
            j++;
        }
        j--;
        i++;
        while(i<end_j && number>0){
            ans.push_back(matrix[i][j]);
            number--;
            i++;
        }
        i--;
        j--;

        while(j>=start_i && number>0){
            ans.push_back(matrix[i][j]);
            number--;
            j--;
        }
        j++;
        i--;
        while(i>start_j && number>0){
            ans.push_back(matrix[i][j]);
            number--;
            i--;
        }
        start_i++;
        start_j++;
        end_i--;
        end_j--;
        }
        return ans;
    }
};
