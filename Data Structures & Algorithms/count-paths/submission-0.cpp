class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> row(n, 1);
        m--;
        while (m>0){
            for(int i= n-2; i>=0; i--){
                row[i]=row[i]+row[i+1];
            }
            m--;

        }
        return row[0];
    }
};
