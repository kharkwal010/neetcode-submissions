class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        for(int i=0; i<points.size(); i++){
            map<pair<int, int>, int> mp;
            for(int j=i+1; j<points.size(); j++){
                int del_x = points[i][0] - points[j][0];
                int del_y = points[i][1] - points[j][1];
                if(del_x==0){
                    del_y = 1;                    
                }
                else if(del_y==0){
                    del_x=1;
                }
                else{
                    int neg =((del_x*del_y) < 0) ? -1 : 1;
                    int div = gcd(del_x, del_y);
                    del_x = neg * abs(del_x/div);
                    del_y = abs(del_y/div);
                }
                mp[{del_x, del_y}]++;
                
                
                ans=max(ans, mp[{del_x, del_y}]+1);                
            }
            mp.clear();
        }
        return ans;
    }
};