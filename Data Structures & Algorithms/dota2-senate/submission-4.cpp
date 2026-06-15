class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rad;
        queue<int> dire;
        for(int i=0; i<senate.size(); i++){
            if(senate[i]=='R') rad.push(i);
            else dire.push(i);
        }
        int i = senate.size();
        while(!rad.empty() && !dire.empty()){
            int r = rad.front();
            rad.pop();
            int d = dire.front();
            dire.pop();
            if(r<d) rad.push(i);
            else dire.push(i);
            i++;
        }
        return (rad.empty()) ? "Dire" : "Radiant";
    }
};