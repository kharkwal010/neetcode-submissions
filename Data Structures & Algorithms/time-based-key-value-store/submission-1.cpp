class TimeMap {
public:
    unordered_map<string,string> mapping;
    unordered_map<string, vector<int>> elements;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        elements[key].push_back(timestamp);
        string k = key + "," + to_string(timestamp); 
        mapping[k]=value;
    }
    
    string get(string key, int timestamp) {
        vector<int> use = elements[key];
        int val;
        int l = 0;
        int r = use.size()-1;

        while(l<=r){
            int m = (l+r)/2;
            if(use[m]==timestamp){
                val = use[m];
                break;
            }
            else if(use[m]<timestamp){
                val = use[m];
                l = m+1;
            }
            else r = m-1;
        }
        string k = key + "," + to_string(val); 
        return mapping[k];
        
    }
};
