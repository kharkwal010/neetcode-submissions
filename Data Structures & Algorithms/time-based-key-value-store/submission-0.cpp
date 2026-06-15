class TimeMap {
public:
    unordered_map<string, map<int, string>> mapping;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mapping[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = mapping[key].upper_bound(timestamp);
        return it == mapping[key].begin() ? "" : prev(it)->second;
    }
};
