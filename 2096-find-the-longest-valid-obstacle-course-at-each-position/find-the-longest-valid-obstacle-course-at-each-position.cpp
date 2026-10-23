class Solution {
public:
    int upper(vector<int>& terms, int ele){
        int l = 0;
        int r = terms.size()-1;
        int ans = r;
        while(l<=r){
            int m = (l+r)/2;
            if(terms[m]>ele){
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> order;
        order.push_back(obstacles[0]);
        int n = obstacles.size();
        vector<int> ans(n);
        ans[0] = 1;
        for(int i=1; i<n; i++){
            if(obstacles[i]>=order.back()){
                order.push_back(obstacles[i]);
                ans[i] = order.size();
            }
            else{
                int j = upper(order, obstacles[i]);
                ans[i] = j+1;
                order[j] = obstacles[i];
            }
        }
        return ans;
    }
};