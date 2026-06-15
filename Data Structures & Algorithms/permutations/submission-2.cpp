class Solution {
public:
    void perm(vector<int>& nums, vector<int> comb, vector<vector<int>>& res, int index){
        if(index==nums.size()){
            res.push_back(comb);
            return;
        }
        for(int i=0; i<comb.size(); i++){
            if(comb[i]==11){
                comb[i] = nums[index];
                perm(nums, comb, res, index+1);
                comb[i] = 11;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> comb(nums.size(), 11);
        vector<vector<int>> res;
        perm(nums, comb, res, 0);
        return res;
    }
};
