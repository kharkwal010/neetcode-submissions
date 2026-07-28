class UndergroundSystem {
public:
    unordered_map<int, pair<int, string>> entry;
    unordered_map<string, pair<int, double>> avg;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        entry[id] = {t, stationName};
        return;
    }
    
    void checkOut(int id, string stationName, int t) {
        auto ele = entry[id];
        string start = ele.second;
        double time = t - ele.first;
        string key = start + "," + stationName;
        if(!avg.count(key)) avg[key] = {1, time};
        else{
            auto term = avg[key];
            int f = term.first;
            double ft = term.second;
            double avg_time = (f*ft + time)/(f+1);
            avg[key] = {f+1, avg_time};
        }
        return;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "," + endStation;
        return avg[key].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */