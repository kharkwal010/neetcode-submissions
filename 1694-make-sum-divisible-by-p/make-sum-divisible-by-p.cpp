class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
       int ans = INT_MAX;
       unordered_map<int, int> index;
       long long sum = 0;
    //    vector<int> prefix(nums.size()+1, 0);
       for(int i=0; i<nums.size(); i++) sum += nums[i];
       int rem = sum%p;
       if(rem==0) return 0;
       index[0] = -1;
       long long add = 0;
       for(int i=0; i<nums.size(); i++){
            add += nums[i];
            int r = add % p;
            int comp = r - rem;
            if(comp<0) comp = comp + p;
            if(index.count(comp)) ans = min(ans, i - index[comp]);
            index[r] = i;
       }
       return (ans==INT_MAX || ans == nums.size()) ? -1 : ans;
    }
};