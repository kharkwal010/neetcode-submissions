class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int escape(vector<int>& source, set<pair<int, int>> visited, vector<int>& target){
        queue<pair<int,int>> q;
        q.push({source[0], source[1]});
        visited.insert({source[0], source[1]});
        int count = 0;
        while(count<2e4){
            if(q.empty()) return 0;
            auto curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;
            for(int i=0; i<4; i++){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr<0 || nc<0 || nr>=1e6 || nc>=1e6) continue;
                if(visited.count({nr, nc})) continue;
                visited.insert({nr, nc});
                if(nr==target[0] && nc==target[1]) return 1;
                count++;
                q.push({nr, nc});
            }
        }
        return 2;

    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        set<pair<int, int>> visited;
        for(auto& b: blocked){
            visited.insert({b[0], b[1]});
        }
        int one = escape(source, visited, target);
        if(one==0) return false;
        if(one==1) return true;
        cout<<one<<endl;
        int two = escape(target, visited, source);
        if(two==0) return false;
        return true;

    }
};