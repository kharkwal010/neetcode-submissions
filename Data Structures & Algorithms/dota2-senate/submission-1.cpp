class Solution {
public:
    string predictPartyVictory(string senate) {
        vector<bool> present(senate.size(), true);
        int r = 0;
        int d = 0;
        for(char c: senate){
            if(c=='R') r++;
            else d++;
        }
        if(r==0) return "Dire";
        if(d==0) return "Radiant";
        int rad = 0;
        int dire = 0;
        while(true){
            for(int i=0; i<senate.size(); i++){
                if(senate[i]=='R' && present[i]){
                    if(dire==0) rad++;
                    else{
                        dire--;
                        present[i]=false;
                        r--;
                        if(r==0) return "Dire";
                    }
                }
                else if(senate[i]=='D' && present[i]){
                    if(rad==0) dire++;
                    else{
                        rad--;
                        present[i]=false;
                        d--;
                        if(d==0) return "Radiant";
                    }
                }
            }
        }
    }
};