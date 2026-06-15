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
        vector<int> starting;
        vector<int> ending;
        for(int i=0; i<intervals.size(); i++){
            starting.push_back(intervals[i].start);
            ending.push_back(intervals[i].end);
        }
        sort(starting.begin(), starting.end());
        sort(ending.begin(), ending.end());
        int count = 0;
        int ans =0;
        int s=0;
        int e=0;
        while(s<starting.size()){
            if(starting[s]<ending[e]){
                count++;
                s++;
            }
            else if(starting[s]==ending[e]){
                s++;
                e++;
            }
            else{
                count--;
                e++;
            }
            ans = max(ans, count);
        }
        return ans;
        
        
    }
};
