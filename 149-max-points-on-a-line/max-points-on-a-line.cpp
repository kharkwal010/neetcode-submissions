class Solution {
public:
    int inf = 10e5;
    int maxPoints(vector<vector<int>>& points) {
        int x = 0;
        unordered_map<int, unordered_map<int, int>> count;
        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                int del_y = (points[j][1] - points[i][1]);
                int del_x = (points[j][0] - points[i][0]);
                int sign = 1;
                if(del_y*del_x<0) sign = -1;
                int div = gcd(del_x, del_y);
                
                int term = count[sign*abs(del_x/div)][abs(del_y/div)]++; 
                x = max(x, term+1);               
            }
            count.clear();
        }
        return x+1;
    }
};