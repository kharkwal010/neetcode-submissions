class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> ele;
        int cnt = 0;
        int i=0;
        int j=nums.size()-1;
        while(i<=j){
            if(ele.count(nums[i])){
                cnt++;
                swap(nums[i], nums[j]);
                nums.pop_back();
                j--;
            }
            else{
                ele.insert(nums[i]);
                i++;
            }
        }
        sort(nums.begin(), nums.end());
        return n-cnt;
    }
};