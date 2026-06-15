class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=1; i<triangle.size(); i++){
            for(int j=0; j<triangle[i].size(); j++){
                int one = (j>0) ? triangle[i-1][j-1] : INT_MAX;
                int two = (j==triangle[i].size()-1) ? INT_MAX : triangle[i-1][j];
                triangle[i][j] = triangle[i][j] + min(one, two);
            }
        }
        int n = triangle.size()-1;
        return *min_element(triangle[n].begin(), triangle[n].end());
    }
};