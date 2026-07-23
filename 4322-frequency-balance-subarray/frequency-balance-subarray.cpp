class Solution {
public:
    int getLength(vector<int>& nums) {
        int ans=1;
        int c=0;
        while(c<nums.size()){
            int len = 0;
            int term = nums[c];
            while(c<nums.size() && nums[c]==term){
                len++;
                c++;
            }
            ans = max(ans, len);
        }
        // cout<<ans<<endl;
        for(int i=0; i<nums.size(); i++){
            unordered_map<int, int> freq;
            vector<int> count(nums.size()+1,0);
            int maxf = 0;
            int n = 0;
            for(int j=i; j<nums.size(); j++){
                freq[nums[j]]++;
                int f = freq[nums[j]];
                count[f]++;
                count[f-1]--;
                if(freq[nums[j]]>maxf){
                    maxf = freq[nums[j]];
                    n=1;
                }
                else if(freq[nums[j]]==maxf) n++;
                if(maxf%2==0){
                    int z = freq.size();
                    if(count[maxf]>0 && count[maxf/2]>0 && count[maxf] + count[maxf/2] ==z){
                        ans = max(ans, j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};