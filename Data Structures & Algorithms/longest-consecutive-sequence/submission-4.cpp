class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers(nums.begin(), nums.end());
        int ans = 0;
        for(int ele: nums){
            int length = 1;
            if(numbers.find(ele-1)==numbers.end()){
                int i = 1;
                while(numbers.find(ele+i)!=numbers.end()){
                    length++;
                    i++;
                }
            }
            ans = max(ans, length);
        }
        return ans;
    }
};
