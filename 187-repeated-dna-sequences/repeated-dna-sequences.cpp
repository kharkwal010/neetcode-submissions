class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10) return {};
        unordered_set<string> visited;
        unordered_set<string> ans;
        int n = s.size();
        for(int i=0; i<=n-10; i++){
            string sub = s.substr(i, 10);
            if(visited.count(sub)) ans.insert(sub);
            visited.insert(sub);
        }
        vector<string> res;
        for(string ele: ans){
            res.push_back(ele);
        }
        return res;
    }
};