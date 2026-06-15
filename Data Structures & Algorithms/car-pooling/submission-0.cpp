class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>> starting;
        vector<vector<int>> ending;
        for(int i=0; i<trips.size(); i++){
            starting.push_back({trips[i][1], trips[i][0]});
            ending.push_back({trips[i][2], trips[i][0]});
        }
        sort(starting.begin(), starting.end());
        sort(ending.begin(), ending.end());
        int s = 0;
        int e = 0;
        int pass = 0;
        while(s<starting.size()){
            if(starting[s][0]<ending[e][0]){
                pass = pass + starting[s][1];
                if(pass > capacity){
                    return false;
                }
                s++;
            }
            else if(starting[s][0]>ending[e][0]){
                pass = pass - ending[e][1];
                e++;
            }
            else{
               pass = pass + starting[s][1] - ending[e][1]; 
               s++;
               e++;
                if(pass > capacity){
                    return false;
                }
            }
        }
        return true;
    }
};