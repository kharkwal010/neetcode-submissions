class MinStack {
public:
    stack<pair<int, int>> min_stack;
    stack<int> astack;
    int minimum = INT_MAX;
    MinStack() {}
    
    void push(int val) {
        astack.push(val);
        minimum = min(val, minimum);
        min_stack.push({val,minimum});
    }
    
    void pop() {
            astack.pop();
            min_stack.pop();
            if(min_stack.empty()){
                minimum = INT_MAX;
            }
            else{
                minimum = min_stack.top().second;  
            }
        }
        
  
    
    int top() {
        return astack.top();
       
    }
    
    int getMin() {
        
        return min_stack.top().second;
      
    }
};
