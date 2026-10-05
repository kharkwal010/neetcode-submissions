class Solution {
public:
    int maxarea(vector<int>& terms){
        int n = terms.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<pair<int, int>> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top().first>terms[i]){
                auto top = st.top();
                st.pop();
                left[top.second] = i - top.second;
            }
            st.push({terms[i], i});
        }
        while(!st.empty()){
            left[st.top().second] = n - st.top().second;
            st.pop();
        }

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top().first>terms[i]){
                auto top = st.top();
                st.pop();
                right[top.second] = top.second - i;
            }
            st.push({terms[i], i});
        }
        while(!st.empty()){
            right[st.top().second] = st.top().second + 1;
            st.pop();
        }

        int area = 0;
        for(int i=0; i<n; i++){
            area = max(area, terms[i]*(left[i]+right[i]-1));
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
       vector<vector<int>> mat(m, vector<int>(n));
       for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            mat[i][j] = matrix[i][j]-'0';
            if(i>0 && mat[i][j]==1) mat[i][j]+=mat[i-1][j];            
        }
       }
       int area = 0;
       for(int i=0; i<m; i++){
            area = max(area, maxarea(mat[i]));
       }
       
       return area;
    }
};