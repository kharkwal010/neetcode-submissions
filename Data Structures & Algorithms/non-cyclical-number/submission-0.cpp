class Solution {
public:
    int sos(int n){
        string num = to_string(n);
        int sum = 0;
        for(int i=0; i<num.size(); i++){
            int digit = int (num[i]-'0');
            sum = sum + digit*digit;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set <int> visited;
        int a =sos(n);
        while(visited.find(a) == visited.end()){
            visited.insert(a);
            if(a==1){
                return true;
            }
            a = sos(a);
        }
        return false;
    }
};
