class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> out;
        for(auto& p: paths){
            out[p[0]]++;
            out[p[1]] +=0;
        }
        for(auto& ele: out){
            if(ele.second==0) return ele.first;
        }
        return "";
    }
};