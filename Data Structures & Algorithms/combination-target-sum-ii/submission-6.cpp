class Solution {
public:
    set<vector<int>> visited;
    void dfs(vector<int>& candidates, int target, vector<int> ans, vector<vector<int>>& res, int i){
        if(target==0 ){
            if(visited.find(ans)==visited.end()){
                res.push_back(ans);
                visited.insert(ans);
            } 
                
            return;
        }
        if(i==candidates.size() || target<0) return;
        dfs(candidates, target, ans, res, i+1);
        ans.push_back(candidates[i]);
        dfs(candidates, target-candidates[i], ans, res, i+1);  
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
       vector<vector<int>> res;
        dfs(candidates, target, {}, res, 0);
        return res;
    }
};
