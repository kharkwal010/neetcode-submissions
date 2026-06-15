class MedianFinder {
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(small.size()>large.size()) large.push(num);
        else small.push(num);
        if(!large.empty() && small.top()>large.top()){
            int s = small.top();
            int l = large.top();
            small.pop();
            large.pop();
            small.push(l);
            large.push(s);
        }
    }
    
    double findMedian() {
        if(small.size()==large.size()) return (small.top()+large.top())/2.0;
        return small.top();
    }
};
