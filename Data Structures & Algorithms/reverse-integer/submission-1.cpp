class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        int one = 0;
        bool positive = true;
        if(s[0]=='-'){
            one++;
            positive = false;
        }
        string str= "";
        if(s.size()>12){
            return 0;
        }
        for(int i=s.size()-1; i>=one; i--){
            str = str + s[i];
        }
        long long ans = stoll(str);
        if(ans>INT_MAX){
            return 0;
        }
        if(positive){
            return ans;
        }
        else  return -1*ans;
    }
};
