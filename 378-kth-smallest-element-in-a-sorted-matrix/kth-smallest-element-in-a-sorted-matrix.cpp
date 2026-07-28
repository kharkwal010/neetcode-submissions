class Solution {
public:
    int check(vector<vector<int>>& matrix, int m){
        int n = matrix.size();
        int c = n-1;
        int count = 0;
        for(int i=0; i<n; i++){
            while(c>=0 && matrix[i][c]>m){
                c--;
            }
            if(c<0) break;
            count += c+1;
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n-1][n-1];
        while(l<r){
            int m = l + (r - l) / 2;
            cout<<m<<endl;
            int count = check(matrix, m);
            if(count>=k) r = m;
            else l = m+1;
        }
        return l;

    }
};