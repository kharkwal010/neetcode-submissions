class Solution {
public:
    vector<int> terms(vector<int>& nums, int k){
        vector<int> val(k,0);
        int n = nums.size();
        for(int tar=0; tar<k; tar++){
            int res = 0;
            for(int i=0; i<nums.size(); i++){
                int mod = abs(nums[i]-tar);
                res += min(mod, k - mod);
            }
            val[tar] = res;
        }
        return val;
    }
    int minOperations(vector<int>& nums, int k) {
       vector<int> even;
       vector<int> odd;
       for(int i=0; i<nums.size(); i++){
            int curr = nums[i]%k;
            if(i%2==0) even.push_back(curr);
            else odd.push_back(curr);
       }
       vector<int> one = terms(even, k);
       vector<int> two = terms(odd, k);
    //    for(int t: one) cout<<t<<" ";
    //    cout<<endl;
    //    for(int t: two) cout<<t<<" ";
       int ans = INT_MAX;
       for(int i=0; i<k; i++){
            for(int j=0; j<k; j++){
                if(i==j) continue;
                ans = min(ans, one[i]+two[j]);
            }
       }
       return ans;
    }
};