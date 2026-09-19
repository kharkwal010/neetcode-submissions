class Solution {
public:
    int sub(vector<int>& terms){
        int n = terms.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        stack<pair<int, int>> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top().first>terms[i]){
                right[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({terms[i], i});
        }
        while(!st.empty()){
            right[st.top().second] = n - st.top().second;
            st.pop();
        }

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top().first>=terms[i]){
                left[st.top().second] = st.top().second - i;
                st.pop();
            }
            st.push({terms[i], i});
        }
        while(!st.empty()){
            left[st.top().second] = st.top().second + 1;
            st.pop();
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            ans += (right[i] * left[i])*terms[i];
        }
        return ans;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[j][i]==1){
                    if(j>0) mat[j][i] = mat[j-1][i] + 1;
                }
            }
        }
        int ans = 0;
        for(int i=0; i<m; i++){
            ans += sub(mat[i]);
        }
        return ans;        
    }
};