class CountSquares {
public:
    unordered_map<int, vector<vector<int>>> row;
    unordered_map<string, int> c;
    CountSquares() {}
    
    void add(vector<int> point) {
       string key = to_string(point[0]) + "," + to_string(point[1]);
       c[key]++;
       row[point[1]].push_back(point);
    }
    
    int count(vector<int> point) {
        int ans = 0;
        for(auto p: row[point[1]]){
            int dis = point[0] - p[0];
            if(dis==0) continue;
            string t = to_string(point[0]) + "," + to_string(point[1]+ dis);
            string tl = to_string(point[0] - dis) + "," + to_string(point[1] + dis);

            string b = to_string(point[0]) + "," + to_string(point[1]- dis);
            string bl = to_string(point[0] - dis) + "," + to_string (point[1] - dis);
            ans = ans + c[t]*c[tl] + c[b]*c[bl];          
        }
        return ans;
    }
};
