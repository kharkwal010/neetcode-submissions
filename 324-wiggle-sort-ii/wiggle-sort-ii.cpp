class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> ans = nums;
        sort(ans.begin(), ans.end());
        int n = ans.size();
        int st = (n+1)/2 - 1;
        for(int i=0; i<n; i+=2){
            nums[i] = ans[st];
            if (i+1<n) nums[i+1] = ans[st + n/2];
            st--;
        }
        return;
    }
};