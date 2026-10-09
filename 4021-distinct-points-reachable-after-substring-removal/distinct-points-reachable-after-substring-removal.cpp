class Solution {
public:
    int distinctPoints(string s, int k) {
        unordered_map<char, pair<int, int>> dir;
        set<pair<int, int>> values;
        dir['U'] = {-1,0};
        dir['D'] = {1,0};
        dir['L'] = {0,-1};
        dir['R'] = {0,1};
        pair<int, int> curr = {0,0};
        for(int i=0; i<k; i++){
            pair<int, int> c = dir[s[i]];
            curr = {curr.first + c.first, curr.second + c.second};
        }
        values.insert(curr);
        cout<<curr.first<<" "<<curr.second<<endl;
        int l = 0;
        for(int i=k; i<s.size(); i++){
            auto nxt = dir[s[i]];
            auto prev = dir[s[l]];
            curr = {curr.first + nxt.first - prev.first, curr.second + nxt.second - prev.second};
            values.insert(curr);
            l++;
        }
        return (int)values.size();
        
    }
};