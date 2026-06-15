class MedianFinder {
public:
    int count = 0;
    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int> maxheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        count++;
        minheap.push(num);
        if(minheap.size()>maxheap.size()){
            auto top = minheap.top();
            minheap.pop();
            maxheap.push(top);
        }
        else{
            auto left = maxheap.top();
            auto right = minheap.top();
            if(left>right){
                maxheap.pop();
                minheap.pop();
                maxheap.push(right);
                minheap.push(left);
            }
        }
    }
    
    double findMedian() {
        if (count%2==1) return maxheap.top();
        return ((double)maxheap.top() + minheap.top()) / 2;
    }
};
