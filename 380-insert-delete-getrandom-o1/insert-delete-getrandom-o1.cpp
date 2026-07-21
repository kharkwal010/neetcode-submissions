class RandomizedSet {
public:
    vector<int> terms;
    unordered_map<int, int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        int n = terms.size();
        mp[val] = n;
        terms.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val)) return false;
        int n = terms.size();
        if(terms[n-1]!=val){
            int index = mp[val];
            terms[index] = terms.back();
            mp[terms.back()] = index;
        }            
        terms.pop_back();
        mp.erase(val);
        return true;
        
    }
    
    int getRandom() {
        int i = rand()%terms.size();
        return terms[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */