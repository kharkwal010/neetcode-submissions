class MinStack {
public:
    stack<int> st;
        stack<int> minimum;
        int mini = INT_MAX;
    
    MinStack() {
   
    }
    
    void push(int val) {
        st.push(val);
        mini = min(mini, val);
       
        minimum.push(mini);
        
    }
    
    void pop() {
      st.pop();
      minimum.pop();
       if(minimum.empty()){
            mini = INT_MAX;
        }
        else{
            mini = minimum.top();
        }
        
    }
    
    int top() {
        return st.top();

    }
    
    int getMin() {
        // vector<int> temp;
        // int mini = st.top();
        // while (!(st.empty())){
        //     int a = st.top();
        //     temp.push_back(a);
        //     st.pop();
        //     mini= min(mini, a);
        // }
        // reverse(temp.begin(), temp.end());
        // for(int i=0; i<temp.size(); i++){
        //     st.push(temp[i]);
        // }
        return minimum.top();

    }
};
