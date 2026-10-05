class Solution {
public:
    int count(vector<int>& terms){
        int n = terms.size();
        vector<int> right(n);
        vector<int> left(n);
        stack<pair<int, int>> st;
        for(int i=0; i<terms.size(); i++){
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
                left[st.top().second] = st.top().second  - i;
                st.pop();
            }
            st.push({terms[i], i});
        }
        while(!st.empty()){
            left[st.top().second] = st.top().second +1;
            st.pop();
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            // cout<<right[i]<<" "<<left[i]<<" "<<terms[i]<<endl;
            ans += (right[i] * left[i])*terms[i];
        }
        
        return ans;

    }
    int numSubmat(vector<vector<int>>& mat) {
        for(int i=1; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==1) mat[i][j] += mat[i-1][j];
            }
        }
         
        int ans = 0;
        for(int i=0; i<mat.size(); i++){
            ans += count(mat[i]);
            // cout<<endl;
        }
        return ans;

    }
};