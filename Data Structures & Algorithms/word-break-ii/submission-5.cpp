class Solution {
public:
    unordered_map<int, bool> memo;
    bool word(string s, vector<string>& words, int i, string ans, vector<string>& comb){
        if(i==s.size()){
            ans.pop_back();
            comb.push_back(ans);
            return true;
        }
        if(memo.count(i)){
            if(memo[i]==false) return false;
        }
        bool res = false;
        for(int j=0; j<words.size(); j++){
            int len = words[j].size();
            if(i+len<=s.size()){
                string sub = s.substr(i, len);                
                if(sub==words[j]) res = word(s, words, i+len, ans + sub + " ", comb) || res;
               
            }
        }
        memo[i] =res;
        return res;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> words;
        word(s, wordDict, 0, "", words);
        return words;
    }
};