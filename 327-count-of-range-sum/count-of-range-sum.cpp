class Solution {
public:
    int low;
    int high;
    vector<long long> merge(vector<long long>& prefix, int l, int r, int& count){
        if(l==r) return {prefix[l]};
        int m = (l + (r - l)/2);
        vector<long long> one = merge(prefix, l, m, count);
        vector<long long> two = merge(prefix, m+1, r, count);
        int x = 0;
        int y = 0;
        for(int i=0; i<two.size(); i++){
            long long llim = two[i] - high;
            long long ulim = two[i] - low;
            while(x<one.size() && one[x]<llim) x++;
            if(x==one.size()) continue;
            while(y<one.size()&& one[y]<=ulim) y++;
            count+=(y-x);
        }

        int i = 0;
        int j = 0;
        vector<long long> res;
        while(i<one.size() || j<two.size()){
            if(i==one.size()){
                res.push_back(two[j]);
                j++;
            }
            else if(j==two.size()){
                res.push_back(one[i]);
                i++;
            }
            else if(one[i]<=two[j]){
                res.push_back(one[i]);
                i++;
            }
            else{
                res.push_back(two[j]);
                j++;
            }
        }
        return res;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        low = lower;
        high = upper;
        vector<long long> prefix(nums.size()+1, 0);
        for(int i=0; i<nums.size(); i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        int count = 0;
        merge(prefix, 0, nums.size(), count);
        return count;

    }
};