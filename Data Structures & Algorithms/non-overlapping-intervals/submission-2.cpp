class Solution {
public:
    bool overlap(vector<int> one, vector <int> two){
        if (one[1]>two[0]){
            return true;
        }
        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // if (intervals.size()==0){
        //     return 0;
        // }
        sort(intervals.begin(), intervals.end());
        vector<int> one= intervals[0];
        vector<int> two;
        int counter=0;
        for(int i=1; i<intervals.size(); i++){
            two= intervals[i];
            if (overlap(one, two)){
                counter++;
                if (one[1]>two[1]){
                    one = two;
                }            
            }
            else{
                one = two;
            }
        }
        return counter;

    }
};
