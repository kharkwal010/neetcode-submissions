class MinStack {
public:
    stack<int> st;
    MinStack() {
   
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
      st.pop();
        
    }
    
    int top() {
        return st.top();

    }
    
    int getMin() {
        vector<int> temp;
        int mini = st.top();
        while (!(st.empty())){
            int a = st.top();
            temp.push_back(a);
            st.pop();
            mini= min(mini, a);
        }
        reverse(temp.begin(), temp.end());
        for(int i=0; i<temp.size(); i++){
            st.push(temp[i]);
        }
        return mini;

    }
};
