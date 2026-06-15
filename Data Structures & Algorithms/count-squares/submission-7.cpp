class CountSquares {
public:
    vector<unordered_set<int>> row;
    vector<vector<int>> grid;
    CountSquares() {
        grid.resize(1001,vector<int>(1001,0));
        row.resize(1002);
    }
    
    void add(vector<int> point) {
        int r = point[0];
        int c = point[1];
        grid[r][c]++;
        row[c].insert(r);
    }
    
    int count(vector<int> point) {
        int r = point[0];
        int c = point[1];
        int num = 0;
        for(int rw: row[c]){
            int dis = r - rw;
            if(dis==0) continue;
            if(dis>0){
                if(c+dis<=1000) num+= grid[r-dis][c] * grid[r-dis][c+dis] * grid[r][c+dis];
                if (c-dis>=0) num+=grid[r-dis][c] * grid[r-dis][c-dis] * grid[r][c-dis];
            }
            else{
                dis = abs(dis);
                if(c+dis<=1000) num+= grid[r+dis][c] * grid[r+dis][c+dis] * grid[r][c+dis];
                if (c-dis>=0) num+=grid[r+dis][c] * grid[r+dis][c-dis] * grid[r][c-dis];
            }
        }
        return num;
    }
};
