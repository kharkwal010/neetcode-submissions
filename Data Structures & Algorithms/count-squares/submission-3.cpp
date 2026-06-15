class CountSquares {
public:
    vector<vector<int>> p = vector<vector<int>>(1001, vector<int>(1001, 0));
    unordered_map<int, vector<int>> row;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int r = point[0];
        int c = point[1];
        p[r][c]++;
        if(p[r][c]==1) row[r].push_back(c);
    }
    
    int count(vector<int> point) {
        int r = point[0];
        int c = point[1];
        int count = 0;
        for(int ele: row[r]){
            int len = c-ele;
            if(len==0) continue;
            if(c-len<0 || c-len>1001) continue;
            if(r-len>=0 && r-len<=1001) count += p[r][c-len]*p[r-len][c]*p[r-len][c-len];
            if(r+len>=0 && r+len<=1001) count+= p[r][c-len]*p[r+len][c]*p[r+len][c-len];
        }
        return count;
    }
};
