class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers(nums.begin(), nums.end());
        
        int maxlen=0;
        for (int num: nums){
            int length=0;
            if (numbers.find(num-1)== numbers.end()){
              
            
                while(numbers.find(num+length)!=numbers.end()){
                    length++;
                    
                }
              
                    maxlen=max(length, maxlen);
                
            }
            
        }
        return maxlen; 
        
    }
};
