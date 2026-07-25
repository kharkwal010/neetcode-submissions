class Solution {
public:    
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> maxheap;
        sort(courses.begin(), courses.end(),[](auto& x, auto& y){
            return x[1]<y[1];
        });
        int time = 0;
        for(int i=0; i<courses.size(); i++){
            if(courses[i][1]<courses[i][0]) continue;
            if(time+courses[i][0]<=courses[i][1]){
                time += courses[i][0];
                maxheap.push(courses[i][0]);
            }
            else{
                if(maxheap.top()>courses[i][0]){
                    time-=maxheap.top();
                    maxheap.pop();
                    time+=courses[i][0];
                    maxheap.push(courses[i][0]);
                }
            }
        }
        return maxheap.size();
    }
};