class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int n1 = n/2;
        int n2 = n - n1;
        vector<unordered_set<int>> left(n1+1);
        vector<unordered_set<int>> right(n2+1);
        //(1<<n1) is 2^n1 actally representing 00, 01, 10, 11  in case of n1=2

        for(int mask = 0; mask<(1<<n1); mask++){
            int cnt = 0;
            int sum = 0;
            for(int i=0; i<n1; i++){
                if((mask & (1<<i))){
                    cnt++;
                    sum+=nums[i];
                }
            }
            left[cnt].insert(sum);
        }

        for(int mask = 0; mask<(1<<n2); mask++){
            int cnt = 0;
            int sum = 0;
            for(int i=0; i<n2; i++){
                if((mask & (1<<i))){
                    cnt++;
                    sum+=nums[n1 + i];
                }
            }
            right[cnt].insert(sum);
        }

        for(int k=1; k<nums.size(); k++){
            if(total*k%n!=0) continue;
            int target = total*k/n;
            for(int i=0; i<n1; i++){
                int j = k - i;
                if(j<0 || j>n2) continue;
                for(int ele: left[i]){
                    int req = target - ele;
                    if(right[j].count(req)) return true;
                }
            }
        }
        return false;
    }
};