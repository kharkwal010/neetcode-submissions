class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        // just keep and expand the window size
        priority_queue<int> maxheap;
        priority_queue<int> maxdel;
        int l = 0;
        long long sum = 0;
        for(int i=0; i<chargeTimes.size(); i++){
            maxheap.push(chargeTimes[i]);
            sum += runningCosts[i];
            while(!maxdel.empty() && maxheap.top()==maxdel.top()){
                maxheap.pop();
                maxdel.pop();
            }
            if(maxheap.top() + sum*(i-l+1)>budget){
                sum -= runningCosts[l];
                maxdel.push(chargeTimes[l]);
                l++;
            }
        }
        return runningCosts.size() - l;

    }
};