class TimeMap {
public:
    unordered_map<string, string> memo;
    unordered_map<string, vector<int>> num;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        num[key].push_back(timestamp);
        key = key+","+to_string(timestamp);
        memo[key] = value;
    }
    
    string get(string key, int timestamp) {
       vector<int> terms = num[key];
       int left = 0;
       int right = terms.size()-1;
       if(terms.size()==0 || terms[left]>timestamp) return "";
       while(left<right){
        int mid = (left+right+1)/2;
        if(terms[mid]==timestamp){
            left = mid;
            break;
        }
        else if(terms[mid]<timestamp) left = mid;
        else right = mid-1;
       }
       
       string k = key + "," + to_string(terms[left]);
       return memo[k];
    }
};
