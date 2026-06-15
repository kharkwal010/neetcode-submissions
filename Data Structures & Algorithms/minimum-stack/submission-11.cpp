class MinStack {
public:
    int minimum = INT_MAX;
    stack<pair<int, int>> s;
    MinStack() {}
    
    void push(int val) {
        s.push({val, minimum});
        minimum = min(val, minimum);
    }
    
    void pop() {
        s.pop();
        if(!s.empty()){
            minimum = s.top().second;
            }
        }    
          
    int top() {
       return s.top().first;
    }
    
    int getMin() {
      return min(s.top().second, s.top().first);
    }
};
