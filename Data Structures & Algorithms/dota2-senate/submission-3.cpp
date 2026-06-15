class Solution {
public:
    string predictPartyVictory(string senate) {
       queue<int> r;
       queue<int> d;
       int n = senate.size();
       for(int i=0; i<senate.size(); i++){
            if(senate[i]=='R') r.push(i);
            else d.push(i);
       }
       while(true){
        if(r.size()==0) return "Dire";
        if(d.size()==0) return "Radiant";
        int rad = r.front();
        r.pop();
        int dire = d.front();
        d.pop();
        if(rad<dire) r.push(rad+n);
        else d.push(dire+n);
       }
    }
};