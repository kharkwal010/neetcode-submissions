class Solution {
public:
    int check(vector<int>& temp, int& n){
        int res = 0;
        sort(temp.rbegin(), temp.rend());
        int minh = INT_MAX;
        for(int i=0; i<n; i++){
            if(temp[i]==0) break;
            minh = min(minh, temp[i]);
            res = max(res, temp[i]*(i+1));
        }
        return res;
    }
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int ans = 0;
        vector<int> temp;
        int m = matrix.size();
        int n = matrix[0].size();
        temp = matrix[m-1];
        ans = max(ans, check(temp, n));
        for(int i=m-2; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(matrix[i][j]==0) continue;
                matrix[i][j] += matrix[i+1][j];
            }
            temp = matrix[i];
            ans = max(ans, check(temp, n));
        }
        return ans;

    }
};