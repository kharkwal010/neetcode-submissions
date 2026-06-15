class Solution {
public:
    bool square(vector<int>& matchsticks, int i, long long s1, long long s2, long long s3, long long s4, int target){
        if(s1>target || s2>target || s3>target || s4>target) return false;
        if(i==matchsticks.size()){
            if(s1==s2 && s2==s3 && s4==s3){
                return true;
            }
            return false;
        }
        bool ans = false;
        ans = ans || square(matchsticks, i+1, s1 + matchsticks[i], s2, s3, s4, target);
        ans = ans || square(matchsticks, i+1, s1 , s2 + matchsticks[i], s3, s4, target);
        ans = ans || square(matchsticks, i+1, s1, s2, s3 + matchsticks[i], s4, target);
        ans = ans || square(matchsticks, i+1, s1, s2, s3, s4 + matchsticks[i], target);
        return ans;
    }
    bool makesquare(vector<int>& matchsticks) {
        long long sum = 0;
        for(int& match: matchsticks){
            sum += match;
        }
        if(sum%4!=0) return false;
        return square(matchsticks, 0, 0, 0, 0, 0, sum/4);
    }
};