/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto&x, auto&y){
            return x.start <y.start;
        });
        priority_queue<int, vector<int>, greater<int>> queue;
        if(intervals.size()==0){
            return 0;
        }
        queue.push(intervals[0].end);
        int counter = 1;
        int res = 1;
        for (int i=1; i<intervals.size(); i++){
            bool flag = false;
            if (intervals[i].start < queue.top()){
                queue.push(intervals[i].end);
            }
            counter = queue.size();
            res = max(res, counter);
            while (queue.size()!=0 && intervals[i].start >= queue.top()){
                queue.pop();
                flag = true;
            }
            if(flag==true){
                queue.push(intervals[i].end);
                }
        }
        return res;
    }
};
