class Solution {
public:    
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> maxheap;
        int sum = 0;
        int ans = 0;
        sort(courses.begin(), courses.end(), [](const auto& a, const auto& b){
            return a[1]<b[1];
        });
        int i = 0;
        while(i<courses.size()){
            int day = courses[i][1];
            while(i<courses.size() && courses[i][1]==day){
                sum += courses[i][0];
                maxheap.push(courses[i][0]);
                i++;
            }
            while(maxheap.size()>ans){
                if(sum<=day){
                    ans = maxheap.size();
                    break;
                }
                sum -= maxheap.top();
                maxheap.pop();
            }
        }
        return ans;
    }
};