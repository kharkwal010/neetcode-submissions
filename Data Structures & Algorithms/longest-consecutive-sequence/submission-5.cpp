class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers(nums.begin(), nums.end());
        int ans = 0;
        for(int ele: nums){
            int length = 1;
            if(numbers.find(ele-1)==numbers.end()){
                while(numbers.find(ele+length)!=numbers.end()){
                    length++;                    
                }
            }
            ans = max(ans, length);
        }
        return ans;
    }
};
