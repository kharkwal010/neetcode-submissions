class Solution {
public:
    int minJumps(vector<int>& nums) {
        if(nums.size()==1) return 0;
        unordered_map<int, vector<int>> pos;
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<nums.size(); i++) pos[nums[i]].push_back(i);
        int maxi = *max_element(nums.begin(), nums.end());
        vector<bool> primes(maxi+1, true);
        for(int i=2; i<=maxi; i++){
            if(!primes[i]) continue;
            for(int j=i; j<=maxi; j+=i){
                if(i!=j) primes[j] = false;
                if(!pos.count(j)) continue;
                for(int e: pos[j]) adj[i].push_back(e);
            }
        }
        vector<bool> visited(nums.size(), false);
        queue<int> q;
        int count = 1;
        q.push(0);
        visited[0] = true;
        vector<bool> usedPrime(maxi + 1, false);
        while(!q.empty()){
            int sz = q.size();
            for(int k=0; k<sz; k++){
                int curr = q.front();
                q.pop();
                if(visited[curr])
                if(curr==nums.size()-2) return count;
                if(!visited[curr+1]){
                    visited[curr+1] = true;
                    q.push(curr+1);
                }
                if(curr>0 && !visited[curr-1]){
                    visited[curr-1] = true;
                    q.push(curr-1);
                }
                
                // cout<<nums[curr]<<" "<<(adj[nums[curr]].size())<<endl;
                int p = nums[curr];

                if(primes[p] && !usedPrime[p]){
                    usedPrime[p] = true;

                    for(int nei : adj[p]){
                        if(visited[nei]) continue;
                        if(nei == nums.size()-1) return count;

                        visited[nei] = true;
                        q.push(nei);
                    }
                }
            }
            count++;
        }
        return -1;    
    }
};