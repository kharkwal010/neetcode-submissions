class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
       int count = 0;
       vector<vector<string>> terms(26);
       for(string w: words){
        terms[w[w.size()-1]-'a'].push_back(w);
       }
       for(int i=s.size()-1; i>=0; i--){
        int curr = s[i]-'a';
        vector<string> temp;
        for(auto& ele: terms[curr]){
            if(ele.size()==1){
                count++;
                continue;
            }
            ele.pop_back();
            int newi = ele[ele.size()-1]-'a';
            if(newi==curr) temp.push_back(ele);
            else terms[newi].push_back(ele);
        }
        terms[curr] = temp;
       }
       return count;

    }
};