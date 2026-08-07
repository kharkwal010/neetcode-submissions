class Solution {
public:
    int find(vector<int>& nums, int k){
        if(nums[0]>k) return 0;
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            int m = (l+r) / 2;
            // cout<<l<<" "<<r<<" "<<m<<endl;
            if(nums[m]>k) r = m-1;
            else l = m +1;
        }
        return l;
    }
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start;
        vector<int> end;
        for(auto f: flowers){
            start.push_back(f[0]);
            end.push_back(f[1]+1);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        vector<int> ans;
        unordered_map<int, int> memo;
        for(int ele: people){
            if(memo.count(ele)){
                ans.push_back(memo[ele]);
                continue;
            }
            int bloom = find(start, ele);
            int dull = find(end, ele);
            ans.push_back(bloom-dull);
            memo[ele] = ans.back();
        }
        return ans;
    }
};