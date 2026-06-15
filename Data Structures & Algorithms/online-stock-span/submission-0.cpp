class StockSpanner {
public:
    vector<int> arr;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 0;
        for(int i=arr.size()-1; i>=0; i--){
            if(arr[i]<=price) count++;
            else break;
        }
        arr.push_back(price);
        return 1+count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */