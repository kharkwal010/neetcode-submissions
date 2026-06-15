class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int num: nums){
            count[num]++;
            if(count.size()>2){
                unordered_map<int, int> ncount;
                for(auto ele: count){
                    if(count[ele.first]>1){
                        ncount[ele.first]=count[ele.first]-1;                        
                    }
                }
                count = ncount;                
            }
        }
        vector<int> ans;
        for(auto term: count){
            int freq = 0;
            for(int num: nums){
                if(num==term.first){
                    freq++;
                }
            }
            if(freq>nums.size()/3){
                ans.push_back(term.first);
            }
        }
        return ans;
    }
};


// at a particular time not more than 2 elements can be present in the hashmap
// if we just check the most freqent ch each time, (they are reasonably more than others),we can maintain the size to O(1)