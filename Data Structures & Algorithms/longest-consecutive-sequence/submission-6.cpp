class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> numbers;
       for(int i=0; i<nums.size(); i++){
        numbers.insert(nums[i]);
       } 
       int ans = 0;
       for(int num: numbers){
        if(numbers.find(num-1)==numbers.end()){
            int count = 0;
            while(numbers.find(num+count)!=numbers.end()){
                count++;
            }
            ans = max(count, ans);
        }
       }
       return ans;
    }
};
