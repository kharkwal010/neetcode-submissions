class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode(int val, ListNode* next=nullptr){
            this->val = val;
            this->next = next;
        }
};
class MyCircularQueue {
public:
    int limit;
    ListNode* start;
    ListNode* last;
    int number = 0;
    MyCircularQueue(int k) {
        limit = k;       
        start = new ListNode(0);
        last = start;
    }
    
    bool enQueue(int value) {
        if(number==limit) return false;
        number++;
        ListNode* curr = new ListNode(value);
        last->next = curr;
        last = last->next;
        return true;
    }
    
    bool deQueue() {
        if(number==0) return false;
        number--;
        ListNode* del = start->next;
        start->next = start->next->next;
        if(number==0) last = start;
        delete(del);
        return true;
    }
    
    int Front() {
        if(number==0) return -1;
        return start->next->val;
    }
    
    int Rear() {
        if(number==0) return -1;
        return last->val;
    }
    
    bool isEmpty() {
        if(number==0) return true;
        return false;
    }
    
    bool isFull() {
        if(number==limit) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */