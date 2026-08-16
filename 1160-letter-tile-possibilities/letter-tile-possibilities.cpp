class Solution {
public:
    unordered_map<char, int> count;
    int backtrack(){
        int res = 1;
        for(auto& c: count){
            if(c.second>0){
                count[c.first]--;
                res += backtrack();
                count[c.first]++;
            }
        }
        return res;
    }
    int numTilePossibilities(string tiles) {
        for(char c: tiles){
            count[c]++;
        }
        return backtrack()-1;
    }
};