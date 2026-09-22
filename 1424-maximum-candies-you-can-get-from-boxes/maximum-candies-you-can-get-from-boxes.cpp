class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;
        int ans = 0;
        for(int i: initialBoxes){
            if(status[i]==1){
                status[i] = 3;
                ans += candies[i];
                q.push(i);
            }
            else status[i] = 2;
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int ele: containedBoxes[curr]){
                if(status[ele]==1){
                    status[ele] = 3;
                    q.push(ele);
                    ans += candies[ele];
                }
                else if(status[ele]==0){
                    status[ele] = 2;
                }
            }
            for(int ele: keys[curr]){
                if(status[ele]==2){
                    status[ele] = 3;
                    q.push(ele);
                    ans += candies[ele];
                }     
                else if(status[ele]==0){
                    status[ele] = 1;
                }           
            }
        }
        return ans;
    }
};