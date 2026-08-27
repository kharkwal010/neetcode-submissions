class Solution {
public:
    unordered_set<string> terms;
    vector<int> memo;
    bool dfs(string& word, int j){
        if(j==word.size()) return true;
        bool ans = false;
        if(memo[j]!=-1) return memo[j];
        string curr = "";
        for(int i=j; i<word.size(); i++){
            curr.push_back(word[i]);
            if(terms.count(curr)) ans = ans || dfs(word, i+1);
        }
        return memo[j] = ans;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(string& s: words) terms.insert(s);
        vector<string> ans;
        for(string s: words){
            terms.erase(s);
            memo.assign(s.size(), -1);
            if(dfs(s, 0)) ans.push_back(s);
            terms.insert(s);
        }
        return ans;
    }
};