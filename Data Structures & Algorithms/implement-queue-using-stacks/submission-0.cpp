class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    void exchange(){
        while(!s1.empty()){
            int top = s1.top();
            s1.pop();
            s2.push(top);
        }
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            exchange();
        }
        int top = s2.top();
        s2.pop();
        return top;
    }
    
    int peek() {
        if(s2.empty()){
            exchange();
        }
        return s2.top();
    }
    
    bool empty() {
        if(s1.empty() && s2.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */