class Solution {
public:
    int index(vector<pair<int, int>>& terms, int& value){
        int l = 0;
        int r = terms.size()-1;
        while(l<r){
            int m = (l+r)/2;
            if(terms[m].first<value) r = m;
            else if(terms[m].first>value) l = m+1;
            else return terms[m].second;
        }
        return terms[l].second;
    }
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int, int>> terms;
        int ans = 0;
       for(int i=0; i<nums.size(); i++){
            if(terms.size()==0 || terms.back().first>nums[i]){
                terms.push_back({nums[i], i});
            }
            else{
                int ind = index(terms, nums[i]);
                ans = max(ans, i - ind);
            }
       }
       return ans;
    }
};