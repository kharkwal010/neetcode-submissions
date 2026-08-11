class Solution {
public:
    bool check(string& s, string& p, vector<int>& removable, int m){
        unordered_set<int> visited;
        for(int i=0; i<m; i++){
            visited.insert(removable[i]);
        }
        int j = 0;
        for(int i=0; i<s.size(); i++){
            if(visited.count(i)) continue;
            if(s[i]==p[j]){
                j++;
                if(j==p.size()) return true;
            }
        }
        return false;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = 0;
        int r = removable.size();
        int ans = 0;
        while(l<=r){
            int m = (l+r) / 2;
            // cout<<l<<" "<<r<<" "<<m<<endl;
            if(check(s, p, removable, m)){
                l = m+1;
                ans = m;
            }
            else r = m-1;
        }
        return ans;

    }
};