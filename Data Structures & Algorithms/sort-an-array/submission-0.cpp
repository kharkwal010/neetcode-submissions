class Solution {
public:
    vector<int> sort(vector<int>& nums, int l, int r){
        if(l==r) return {nums[l]};
        int m = (l+r) / 2;
        vector<int> one = sort(nums, l, m);
        vector<int> two = sort(nums, m+1, r);
        vector<int> ans;
        int i=0;
        int j=0;
        while(i<one.size() || j<two.size()){
            if(i==one.size()){
                ans.push_back(two[j]);
                j++;
            }
            else if(j==two.size()){
                ans.push_back(one[i]);
                i++;
            }
            else if(one[i]<two[j]){
                ans.push_back(one[i]);
                i++;
            } 
            else{
                ans.push_back(two[j]);
                j++;
            }          
        }
        return ans;

    }
    vector<int> sortArray(vector<int>& nums) {
        return sort(nums, 0, nums.size()-1);
    }
};