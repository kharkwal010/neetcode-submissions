class Solution {
public:
    set<pair<int, int>> visited;
    unordered_map<int, vector<pair<int, int>>> row;
    unordered_map<int, vector<pair<int, int>>> col;

    void dfs(int r, int c){
        visited.insert({r, c});
        for(auto& ele : row[r]){
            if(visited.count(ele)) continue;
            visited.insert(ele);
            dfs(ele.first, ele.second);
        }
        for(auto& ele: col[c]){
            if(visited.count(ele)) continue;
            visited.insert(ele);
            dfs(ele.first, ele.second);
        }
    }

    int removeStones(vector<vector<int>>& stones) {   
        int n = stones.size();     
        for(auto& ele: stones){
            row[ele[0]].push_back({ele[0], ele[1]});
            col[ele[1]].push_back({ele[0], ele[1]});
        }
        int count = 0;
        for(auto& ele: stones){
            if(visited.count({ele[0], ele[1]})) continue;
            visited.insert({ele[0], ele[1]});
            count++;
            dfs(ele[0], ele[1]);
        }
        return n - count;
        
    }
};