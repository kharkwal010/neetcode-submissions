class MyQueue {
public:
    stack<int> one;
    stack<int> two;

    MyQueue() {
        
    }
    
    void push(int x) {
        one.push(x);
    }
    
    int pop() {
        if(!two.empty()){
            int t = two.top();
            two.pop();
            return t;
        }
        while(!one.empty()){
            int t = one.top();
            one.pop();
            two.push(t);
        }
        int t = two.top();
        two.pop();
        return t;
    }
    
    int peek() {
        if(!two.empty()){
            return two.top();
        }
        while(!one.empty()){
            int t = one.top();
            one.pop();
            two.push(t);
        }
        return two.top();
    }
    
    bool empty() {
        if(!one.empty() || !two.empty()) return false;
        return true;
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