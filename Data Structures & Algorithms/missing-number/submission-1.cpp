class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int numbers = nums.size();
        int sum = accumulate(nums.begin(), nums.end(),0);
        int check = 0;
        for(int i=0; i<=numbers; i++){
            check = i+check;
        }
        return check- sum;
    }
};
