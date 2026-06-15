class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int num: nums){
            count[num]++;
            if(count.size()>2){
                unordered_map<int, int> temp;
                for(auto ele: count){
                    if(count[ele.first]>1){
                        temp[ele.first] = count[ele.first]-1;
                    }
                }
                count = temp;
            }
        }
        vector<int> ans;
        unordered_map<int, int> freq;
        for(int num: nums){
            if(count.find(num)!=count.end()){
                freq[num]++;
            }
        }
        for(auto ele: freq){
            if(freq[ele.first]>nums.size()/3){
                ans.push_back(ele.first);  
            }
        }
        return ans;
    }
};