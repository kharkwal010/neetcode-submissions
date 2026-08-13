class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long long> prefix(2*n+1,0);
        for(int i=0; i<2*n; i++){
            prefix[i+1] = prefix[i] + nums[i%n];
        }
        int full = target/prefix[n];
        target = target % prefix[n];
        if(target==0) return full*n;
        unordered_map<long long, int> index;
        int ans = INT_MAX;
        if(prefix[n]>=target){
            // cout<<"hello"<<endl;
            for(int i=0; i<prefix.size(); i++){
                long long tar = prefix[i] - target;
                if(index.count(tar)){
                    ans = min(ans, i - index[tar]);
                }
                index[prefix[i]] = i;
            }
        }
        if(ans==INT_MAX) return -1;
        return full*n + ans;
        

        
        
    }
};