class Solution {
public:    
    unordered_set<string> terms;
    void backtrack(string tiles, vector<bool>& visited, int i, string curr){
        if(i==tiles.size()) return;
        for(int j=0; j<tiles.size(); j++){
            if(visited[j]) continue;
            curr.push_back(tiles[j]);
            if(!terms.count(curr)){
                terms.insert(curr);
                visited[j] = true;
                backtrack(tiles, visited, i+1, curr);
            }
            curr.pop_back();
            visited[j] = false;
        }
        return;

    }
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<bool> visited(n, false);
        backtrack(tiles, visited, 0, "");
        return terms.size();

    }
};