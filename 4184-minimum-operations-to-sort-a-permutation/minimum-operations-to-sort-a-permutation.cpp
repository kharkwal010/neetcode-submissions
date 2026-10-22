class Solution {
public:
    int minOperations(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while(nums[i]!=0) i++;
        int pos = i;
        bool complete = true;
        for(int j=pos+1; j<pos+nums.size(); j++){
            int c = j%n;
            int p = (j-1)%n;
            if(nums[c]-nums[p]!=1){
                complete = false;
                break;
            }
        }
        int ans = INT_MAX;
        if(complete){
            ans = min({ans, pos, n - pos + 2});
        }
        complete = true;
        int j = pos-1;
        int k = 0;
        while(k<n-1){
            int c = (n+j)%n;
            int p = (n+j+1)%n;
            if(nums[c]-nums[p]!=1){
                complete = false;
                break;
            }
            j--;
            k++;
        }
        if(complete) ans = min({ans, pos+2, n - pos});
        if(ans==INT_MAX) return -1;
        return ans;
    }
};