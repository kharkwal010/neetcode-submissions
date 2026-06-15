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
        vector<int> starts;
        vector<int> ends;
        for(auto interval: intervals){
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int end = 0;
        int start =0;
        int meet = 0;
        int ans = 0;
        while(start<starts.size()){
            if(ends[end]>starts[start]){
                meet++;
                start++;
            } 
            else{
                end++;
                meet--;
            }  
            ans = max(ans, meet);


        }
        return ans;
        
        
    }
};
