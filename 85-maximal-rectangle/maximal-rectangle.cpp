class Solution {
public:
    int rectangle(vector<int>& nums){
        int n = nums.size();
        vector<int> right(n);
        vector<int> left(n);
        stack<pair<int, int>> st;
        for(int i=0; i<nums.size(); i++){
            while(!st.empty() && st.top().first>nums[i]){
                auto top = st.top();
                st.pop();
                right[top.second] = i - top.second;
            }
            st.push({nums[i], i});
        }
        while(!st.empty()){
            int top = st.top().second;
            st.pop();
            right[top] = n - top;
        }

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top().first>nums[i]){
                auto top = st.top();
                st.pop();
                left[top.second] = top.second - i - 1;
            }
            st.push({nums[i], i});
        }
        while(!st.empty()){
            int top = st.top().second;
            st.pop();
            left[top] = top;
        }

        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans = max(ans, nums[i]*(right[i]+left[i]));
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> mat(m, vector<int>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1') mat[i][j] = 1;
                else mat[i][j] = 0;
            }
        }
        for(int i=0; i<matrix[0].size(); i++){
            for(int j = 1; j<matrix.size(); j++){
                if(mat[j][i]==1){
                    mat[j][i]+=mat[j-1][i];
                }
            }
        }
        int ans = 0;
        for(auto& terms: mat){
            ans = max(ans, rectangle(terms));
        }
        return ans;

    }
};