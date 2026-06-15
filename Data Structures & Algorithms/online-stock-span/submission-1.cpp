class StockSpanner {
public:
    stack<pair<int, int>> st;
    int i=1;
    StockSpanner() {
        st.push({INT_MAX, 0});
    }
    
    int next(int price) {
      while(st.top().first<=price){
        st.pop();
      }
      int ans = i - st.top().second;
      st.push({price, i});
      i++;
      return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */