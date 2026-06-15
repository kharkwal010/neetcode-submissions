class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> money(2, 0);
        for(int bill: bills){
            if(bill==5){
                money[0]++;
            }
            if(bill==10){
                if(money[0]==0){
                    return false;
                }
                else{
                    money[1]++;
                    money[0]--;
                }
            }
            if(bill==20){
                if(money[0]>0 && money[1]>0){
                    money[0]--;
                    money[1]--;
                }
                else if(money[0]>=3){
                    money[0]=money[0]-3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};