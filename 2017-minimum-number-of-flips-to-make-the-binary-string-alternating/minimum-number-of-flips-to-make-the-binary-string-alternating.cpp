class Solution {
public:
    int minFlips(string s) {
        int j = s.size();
        int even0 = 0;
        int even1 = 0;
        int ans = INT_MAX;
        for(int i=0; i<j*2; i++){
            if(i%2==0){
                if(s[i%j]=='0') even1++;
                else even0++;
            }
            else{
                if(s[i%j]=='0') even0++;
                else even1++;
            }
            if(i>=j){
                if((i-j)%2==0){
                    if(s[i-j]=='0')even1--;
                    else even0--;
                }
                else{
                    if(s[i-j]=='0') even0--;
                    else even1--;
                }
                ans = min(ans, min(even1, even0));
            }

        }
        ans = min(ans, min(even1, even0));
        return ans;

    }
};