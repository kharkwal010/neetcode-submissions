class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numbers;
        for(int i=0; i<nums.size(); i++){
            if(numbers.find(nums[i])!=numbers.end()){
                if(i-numbers[nums[i]]<=k){
                    return true;
                }
            }
            numbers[nums[i]]=i;
        }
        return false;
    }
};