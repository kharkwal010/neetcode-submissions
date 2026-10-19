class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       unordered_map<int , int> count;
       int odd = 0;
       int i = 0;
       int terms = 0;
       int ans = 0;
       int l = 0;
       while(i<nums.size()){
            if(nums[i]%2==1){
                odd++;
                count[i] = terms+1;
                if(odd>k){
                    while(nums[l]%2==0) l++;
                    ans += count[l]*count[i];
                    l++;
                    odd--;
                }   
                terms = -1;             
            }
            terms++;
            i++;
       }
    //    cout<<terms<<endl;
       if(odd==k){
            while(nums[l]%2==0) l++;
            ans += count[l]*(terms+1);
       }
       return ans;
    }
};