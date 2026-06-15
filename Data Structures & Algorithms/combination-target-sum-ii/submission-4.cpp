class Solution {
public:
    set<vector<int>> visited;
    void dfs(vector<int>& candidates, int target, vector<int> ans, vector<vector<int>>& res, int layer){
        if(target==0 ){
            if(visited.find(ans)==visited.end()){
                res.push_back(ans);
                visited.insert(ans);
            } 
                
            return;
        }
        if(target<0) return;
        for(int i=layer; i<candidates.size(); i++){
            ans.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], ans, res, i+1);
            ans.pop_back();
        }        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
       vector<vector<int>> res;
        dfs(candidates, target, {}, res, 0);
        return res;
    }
};
