class MedianFinder {
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(small.empty() || small.top()>num){
            small.push(num);
        }
        else large.push(num);
        if(small.size()>1+large.size()){
            int top = small.top();
            small.pop();
            large.push(top);
        }
        else if(small.size()+1<large.size()){
            int top = large.top();
            large.pop();
            small.push(top);
        }
        return;        
    }
    
    double findMedian() {
        if(small.size()==large.size()){
            int one = small.top();
            int two = large.top();
            return (double) (one + two)/2;
        }
        else if(small.size()>large.size()) return small.top();
        else return large.top();
    }
};
