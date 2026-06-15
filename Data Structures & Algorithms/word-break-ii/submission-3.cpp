class Solution {
public:
    void comb(string& s, vector<string>& words, string ans, int i, vector<string>& res){
        if(i==s.size()){
            res.push_back(ans);
            return;
        }
        for(string ele: words){
            if(i+ele.size()>s.size()) continue;
            string part = s.substr(i, ele.size());
            if(part==ele){
                string nans = ans;
                if(nans.size()!=0) nans = nans + " ";   
                nans = nans + ele;         
                comb(s, words, nans, i+ele.size(), res);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        comb(s , wordDict, "", 0, res);
        return res;
    }
};