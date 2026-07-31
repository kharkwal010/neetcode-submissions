class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        queue<int> q;
        q.push(0);
        unordered_map<int, vector<int>> index;
        for(int i=0; i<n; i++){
            index[arr[i]].push_back(i);
        }
        int count = 1;
        while(!q.empty()){
            int size = q.size();
            for(int j=0; j<size; j++){
                int i = q.front();
                q.pop();
                int curr = arr[i];
                for(int& ind : index[curr]){
                    if(dp[ind]!=INT_MAX) continue;
                    dp[ind] = count; 
                    q.push(ind);                   
                }
                index.erase(curr);
                if(i+1<n && dp[i+1]==INT_MAX){
                    dp[i+1] = count;
                    q.push(i+1);
                }
                if(i-1>=0 && dp[i-1]==INT_MAX){
                    dp[i-1] = count;
                    q.push(i-1);
                }
            }
            count++;
        }
        return dp[n-1];
        
    }
};