class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        if(s.size()>t.size()) return false;
        vector<int> right(t.size(), 0);
        int found = 0;
        int n = s.size();
        int curr = n-1;
        for(int i=t.size()-1; i>=0; i--){
            if(s[curr]==t[i]){
                found++;
                curr--;
                if(curr<0) return true;
            }
            right[i] = found;
        }
        found = 0;
        for(int i=0; i<t.size(); i++){
            int next = (i<t.size()-1) ? right[i+1] : 0;
            if(s[found]==t[i]){
                found++;
            }
            else if(found+next+1>=n) return true;
        }
        return false;
    }
};