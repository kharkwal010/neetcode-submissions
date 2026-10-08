class EventManager {
public:
    priority_queue<pair<int, int>> maxheap;
    unordered_map<int, int> priority;
    int maxi = 1e9;
    EventManager(vector<vector<int>>& events) {
        for(auto ele: events){
            priority[ele[0]] = ele[1];
            maxheap.push({ele[1], maxi-ele[0]});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        if(priority[eventId]==newPriority || !priority.count(eventId)) return;
        maxheap.push({newPriority, maxi - eventId});
        priority[eventId] = newPriority;
        return;
    }
    
    int pollHighest() {
        // cout<<maxheap.size()<<endl;
        if(maxheap.size()==0) return -1;
        while(true){
            if(maxheap.size()==0) return -1;
            auto top = maxheap.top();
            maxheap.pop();
            int id = maxi - top.second;
            // cout<<id<<" "<<top.first<<endl;
            if(!priority.count(id)) continue;
            if(priority[id]==top.first){
                // cout<<endl;
                priority.erase(id);
                return id;
            }
        }
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */