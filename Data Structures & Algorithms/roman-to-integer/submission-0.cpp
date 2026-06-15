class Solution {
public:
    int romanToInt(string s) {
    unordered_map<char, int> nums = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int ans = 0;
    for(int i = 0; i<s.size(); i++){
        if(i<s.size()-1 && nums[s[i]]<nums[s[i+1]]){
            ans = ans + nums[s[i+1]] - nums[s[i]];
            i++;
        }
        else ans = ans + nums[s[i]];
    }
    return ans;

    }
};