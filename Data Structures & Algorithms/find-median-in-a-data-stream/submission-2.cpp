class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size()==right.size()) left.push(num);
        else right.push(num);
        int l = left.top();
        int r;
        if (!right.empty()) r = right.top();
        if(!right.empty() && l>r){
            left.pop();
            right.pop();
            left.push(r);
            right.push(l);
        }
    }
    
    double findMedian() {
        if(left.size()==right.size()) return ((double)left.top() + right.top())/2;
        return left.top();
    }
};
