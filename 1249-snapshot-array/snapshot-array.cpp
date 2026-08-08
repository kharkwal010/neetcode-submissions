class SnapshotArray {
public:
    vector<vector<pair<int,int>>> arr;
    int time = 0;
    SnapshotArray(int length) {
        arr.resize(length);
    }
    
    void set(int index, int val) {
        if(!arr[index].empty() && arr[index].back().first==time){
            arr[index].pop_back();
        }
        arr[index].push_back({time, val});
        return;
    }
    
    int snap() {
        time++;
        return time-1;
    }
    
    int get(int index, int snap_id) {
        // vector<pair<int,int>> terms = arr[index];
        if(arr[index].size()==0 || arr[index][0].first>snap_id) return 0;
        int l = 0;
        int r = arr[index].size() - 1;
        int ans = 0;
        while(l<=r){
            int m = (l + r) / 2;
            if(arr[index][m].first>snap_id) r = m - 1;
            else{
                ans = m;
                l = m + 1;
            }
        }
        return arr[index][ans].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */