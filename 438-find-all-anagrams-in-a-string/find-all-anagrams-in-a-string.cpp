class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size()) return {};
        int n = p.size();
        vector<int> one(26, 0);
        vector<int> two(26, 0);
        for(char c: p) one[c-'a']++;
        for(int i=0; i<n; i++){
            two[s[i]-'a']++;
        }
        vector<int> ans;
        if(one==two) ans.push_back(0);
        for(int i=n; i<s.size(); i++){
            two[s[i]-'a']++;
            two[s[i-n]-'a']--;
            if(one==two) ans.push_back(i-n+1);
        }
        return ans;
    }
};