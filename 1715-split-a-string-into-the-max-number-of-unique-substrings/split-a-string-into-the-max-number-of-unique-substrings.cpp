class Solution {
public:
    unordered_set<string> visited;
    void elements(string s, int i, int ele, int& ans){
        if(i==s.size()){
            ans = max(ans, ele);
            return;
        }
        for(int j=i; j<s.size(); j++){
            string sub = s.substr(i, j-i+1);
            if(visited.count(sub)) continue;
            visited.insert(sub);
            elements(s, j+1, ele+1, ans);
            visited.erase(sub);
        }
        return;
    }
    int maxUniqueSplit(string s) {
        int ans = 0;
        elements(s, 0, 0, ans);
        return ans;
    }
};