class Solution {
public:    
    set<pair<int, int>> block;
    bool escape(vector<int>& source, int b, vector<int>& target){
        vector<vector<int>> dir = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        b = (b*(b-1))/2;
        
        set<pair<int, int>> visited = block;
        queue<pair<int, int>> q;
        q.push({source[0], source[1]});
        visited.insert({source[0], source[1]});
        while(b>0){
            if(q.empty()) return false;
            auto top = q.front();
            q.pop();
            int r = top.first;
            int c = top.second;
            
            for(int i=0; i<4; i++){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr<0 || nr>=1e6 || nc<0 || nc>=1e6 || visited.count({nr, nc})) continue;
                visited.insert({nr, nc});
                if(nr==target[0] && nc==target[1]) return true;
                b--;
                q.push({nr, nc});
            }          

        }
        return true;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        for(auto ele: blocked) block.insert({ele[0], ele[1]});
        int n = blocked.size();
        return escape(source, n, target) && escape(target, n, source);
        
    }
};