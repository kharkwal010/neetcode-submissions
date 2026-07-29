class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        vector<int> one(26, 0);
        for(char c: s1) one[c-'a']++;
        vector<int> two(26, 0);
        for(int i=0; i<s1.size(); i++){
            two[s2[i]-'a']++;
        }
        if(one==two) return true;
        int l = 0;
        for(int i = s1.size(); i<s2.size(); i++){
            two[s2[i]-'a']++;
            two[s2[l]-'a']--;
            l++;
            if(one==two) return true;
        }
        return false;
    }
};