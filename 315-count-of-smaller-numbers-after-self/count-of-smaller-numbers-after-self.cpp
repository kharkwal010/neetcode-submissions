class Solution {
public:
    vector<int> res;
    vector<pair<int, int>> merge(vector<int>& nums, int l, int r){
        if(l==r){
            return {{nums[l], l}};
        }
        int m = (r + l) / 2;
        vector<pair<int, int>> left = merge(nums, l, m);
        vector<pair<int, int>> right = merge(nums, m+1, r);
        int count = 0;
        vector<pair<int, int>> ans;
        int i=0;
        int j=0;
        while(i<left.size() || j<right.size()){
            if(j==right.size()){
                ans.push_back(left[i]);
                res[left[i].second] += count;
                i++;
            }
            else if(i==left.size()){
                ans.push_back(right[j]);
                j++;
            }
            else if(left[i].first<=right[j].first){
                ans.push_back(left[i]);
                res[left[i].second] += count;
                i++;
            }
            else{
                ans.push_back(right[j]);
                count++;
                j++;
            }
        }
        return ans;        
    }
    vector<int> countSmaller(vector<int>& nums) {
        res.resize(nums.size(), 0);
        merge(nums, 0, nums.size()-1);
        return res;
    }
};