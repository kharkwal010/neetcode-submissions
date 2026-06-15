class Solution {
public:
    void word(string s, vector<string>& words, int i, string ans, vector<string>& comb){
        if(i==s.size()){
            ans.pop_back();
            comb.push_back(ans);
            return;
        }
        for(int j=0; j<words.size(); j++){
            int len = words[j].size();
            if(i+len<=s.size()){
                string sub = s.substr(i, len);                
                if(sub==words[j]) word(s, words, i+len, ans + sub + " ", comb);
               
            }
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> words;
        word(s, wordDict, 0, "", words);
        return words;
    }
};