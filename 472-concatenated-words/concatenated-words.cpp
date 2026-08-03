class Solution {
public:
    unordered_set<string> nums;
    unordered_map<int, bool> memo;
    bool dfs(string word, int j){
        if(j==word.size()) return true;
        if(memo.count(j)) return memo[j];
        
        for(int i=j; i<word.size(); i++){
            string pre = word.substr(j, i-j+1);
            if(nums.count(pre) && dfs(word, i+1)){
                 return memo[j] = true;
            }
        }
        return memo[j] = false;
        
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        for(string& s: words) nums.insert(s);
        for(string w: words){
            memo.clear();
            nums.erase(w);
            if(dfs(w,0)) ans.push_back(w);
            nums.insert(w);
        }
        return ans;
    }
};