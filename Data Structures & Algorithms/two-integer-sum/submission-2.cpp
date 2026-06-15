class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> index;
        for (int i =0; i< nums.size(); i++){
            int compliment = target - nums[i];
            if (index.find(compliment) != index.end()){
                return { index[compliment], i};
            }      // index[compliment] phele aaya tha and index[i] ka compliment h
            index[nums[i]]=i;
            

        }
        
    }
};
