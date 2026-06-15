class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int countk = 0;
        vector<bool> present(51, 0);
        for(int n: nums){
            if(n==k) countk++;
            present[n]=true;
        }
        int ans = countk;
        
        for(int i=0; i<=51; i++){
            if(present[i]==false || i==k) continue;
            int other = 0;
            int res = 0;
            for(int n: nums){
                if(n==i) other++;
                else if(n==k) other--;
                other = max(0, other);
                res = max(res, other);
            }
            ans = max(ans, countk + res);
        }
        return ans;
    }
};