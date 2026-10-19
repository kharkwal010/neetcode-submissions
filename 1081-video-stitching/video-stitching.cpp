class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        int end = 0;
        int i = 0;
        int count = 0;
        while(i<clips.size()){
            int prevend = end;
            while(i<clips.size() && clips[i][0]<=prevend){
                end = max(end, clips[i][1]);
                i++;
            }
            count++;
            if(end>=time) return count; 
            if(prevend==end) return -1;
        }
        return -1;
    }
};