class MinStack {
public:
    int minimum = INT_MAX;
    stack<pair<int, int>> s;
    MinStack() {}
    
    void push(int val) {
        minimum = min(val, minimum);
        s.push({val, minimum});
    }
    
    void pop() {
        s.pop();
        if(!s.empty()){
            minimum = s.top().second;
            } 
        else minimum = INT_MAX;
        }    
          
    int top() {
       return s.top().first;
    }
    
    int getMin() {
      return minimum;
    }
};
