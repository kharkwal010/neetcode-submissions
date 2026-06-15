class Solution {
public:
    int sos(int n){
        int ans = 0;
        int num;
        while(n>0){
            num = n%10;
            n = n/10;
            ans = ans + num*num;           
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_set <int> visited;
        int a =sos(n);
        while(!visited.count(a)){
            visited.insert(a);
            if(a==1){
                return true;
            }
            a = sos(a);
        }
        return false;
    }
};
