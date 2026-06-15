class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
         vector<pair<int,int>> mid;
        for (int i =0; i<position.size(); i++){
            mid.push_back({target - position[i], speed[i]});
        }
        sort(mid.begin(), mid.end());
    vector <double> time;
    for (int i =0; i<position.size(); i++){
        time.push_back(double(mid[i].first)/mid[i].second);
    }
    int counter=time.size();
    stack <double> fleet;
    for (double t: time){
      if(fleet.empty() || t>fleet.top()){
        fleet.push(t);
      }
        
    }
    return fleet.size();

    }
};
